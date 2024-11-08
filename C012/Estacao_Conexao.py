import threading
import queue
import time
import matplotlib.pyplot as plt

class Dispositivo:
    def __init__(self, nome, prioridade=1, start_time=None, duration=5):
        self.nome = nome
        self.prioridade = prioridade
        self.start_time = start_time or time.time()
        self.original_start_time = self.start_time
        self.duration = duration

    def reset_start_time(self):
        self.start_time = time.time()

    def __repr__(self):
        return f"{self.nome} de prioridade {self.prioridade} com uma duração de {self.duration}s"

class Estacao:
    def __init__(self):
        self.semaforo = threading.Semaphore(1)  #definindo um semáforo com um recurso disponível

    #cada dispositivo será conectado a estação após a seção crítica
    def configurar(self, dispositivo):
        with self.semaforo:
            wait_time = time.time() - dispositivo.start_time
            print(f"{threading.current_thread().name} criou uma conexão com {dispositivo} após esperar {wait_time:.2f} segundos")
            time.sleep(dispositivo.duration)
        return wait_time

class ProcessoEstacaoPriority(threading.Thread):
    def __init__(self, estacoes, fila, name, wait_times, execution_order):
        super().__init__(name=name)
        self.estacoes = estacoes
        self.fila = fila
        self.wait_times = wait_times
        self.execution_order = execution_order

    #prioridade da estação e disponibilidade para conexão
    def run(self):
        while True:
            dispositivo = self._get_highest_priority()
            if dispositivo is None:
                break
            estacao = self._get_available_estacao()
            if estacao is not None:
                print(f"{threading.current_thread().name} pronto para conectar com o {dispositivo}")
                wait_time = estacao.configurar(dispositivo)
                self.wait_times.append(wait_time)
                self.execution_order.append((dispositivo.nome, dispositivo.duration))
                self.fila.task_done()

    def _get_highest_priority(self):
        max_priority = float('inf')
        highest_priority_device = None
        highest_priority_index = -1
        for i, dev in enumerate(self.fila.queue):
            if dev.prioridade < max_priority:
                max_priority = dev.prioridade
                highest_priority_device = dev
                highest_priority_index = i
        if highest_priority_device is not None:
            del self.fila.queue[highest_priority_index]
        return highest_priority_device

    def _get_available_estacao(self):
        for estacao in self.estacoes:
            if estacao.semaforo._value > 0:
                return estacao
        return None

class ProcessoEstacaoSJF(threading.Thread):
    def __init__(self, estacoes, fila, name, wait_times, execution_order):
        super().__init__(name=name) #chama o construtor da classe base threading.Thread
        self.estacoes = estacoes #armazena a lista de estações disponíveis para configuração
        self.fila = fila #armazena a fila de dispositivos a serem configurados
        self.wait_times = wait_times #lista para armazenar os tempos de espera de cada
        self.execution_order = execution_order #ordem execução

    def run(self):
        while True:
            dispositivo = self._get_shortest_job() #método que retorna o dispositivo com o menor tempo de duração na fila.
            if dispositivo is None:
                break
            estacao = self._get_available_estacao() #método que busca uma etação disponível (que já passou pelo semáforo)
            if estacao is not None:
                print(f"{threading.current_thread().name} pronto para conectar com o {dispositivo}")
                wait_time = estacao.configurar(dispositivo)
                self.wait_times.append(wait_time) #adiciona o tempo de espera a lista
                self.execution_order.append((dispositivo.nome, dispositivo.duration)) #adiciona a ordem de execução a lista
                self.fila.task_done()

    #FUNÇÃO PARA CALCULAR A MENOR DURAÇÃO
    def _get_shortest_job(self):
        min_duration = float('inf')
        shortest_job = None
        shortest_job_index = -1
        for i, dev in enumerate(self.fila.queue):
            if dev.duration < min_duration:
                min_duration = dev.duration
                shortest_job = dev
                shortest_job_index = i
        if shortest_job is not None:
            del self.fila.queue[shortest_job_index]
        return shortest_job

    #FUNÇÃO PARA VERIFICAR DISPONIBILIDADE COM SEMÁFORO
    def _get_available_estacao(self):
        for estacao in self.estacoes:
            if estacao.semaforo._value > 0:
                return estacao
        return None

def run_sjf(dispositivos): #EXECUÇÃO POR MENOR TEMPO
    estacoes = [Estacao() for _ in range(4)]
    fila = queue.Queue()
    wait_times = []
    execution_order = []

    #ADICIONANDO DISPOSITIVOS A FILA
    for dev in dispositivos:
        fila.put(dev)
        time.sleep(1)  #adiciona um delay de 1 segundo entre cada dispositivo

    #CRIANDO AS THREADS PARA CONFIGURAÇÃO DAS ESTAÇÕES
    threads = [ProcessoEstacaoSJF(estacoes, fila, name=f"Estacao-{i+1}", wait_times=wait_times, execution_order=execution_order) for i in range(4)]
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()

    avg_wait_time = sum(wait_times) / len(wait_times)
    print(f"Tempo médio de espera (SJF): {avg_wait_time:.2f} segundos")

    return execution_order, avg_wait_time

def run_priority(dispositivos): #EXECUÇÃO POR PRIORIDADE
    estacoes = [Estacao() for _ in range(4)]
    fila = queue.Queue()
    wait_times = []
    execution_order = []

    #ADICIONANDO DISPOSITIVOS A FILA
    for dev in dispositivos:
        fila.put(dev)
        time.sleep(1)  #adiciona um delay de 1 segundo entre cada dispositivo

    #CRIANDO E INICIANDO AS THREADS
    threads = [ProcessoEstacaoPriority(estacoes, fila, name=f"Estacao-{i+1}", wait_times=wait_times, execution_order=execution_order) for i in range(4)]
    for thread in threads:
        thread.start()
    for thread in threads:
        thread.join()

    avg_wait_time = sum(wait_times) / len(wait_times)
    print(f"Tempo médio de espera (Prioridade): {avg_wait_time:.2f} segundos")

    return execution_order, avg_wait_time

if __name__ == "__main__":
    #INSTANCIANDO OS DISPOSITIVOS COM OS MESMOS VALORES
    dispositivos = [
        Dispositivo("Dispositivo1", prioridade=5, duration=4),
        Dispositivo("Dispositivo2", prioridade=2, duration=3),
        Dispositivo("Dispositivo3", prioridade=3, duration=2),
        Dispositivo("Dispositivo4", prioridade=1, duration=6),
        Dispositivo("Dispositivo5", prioridade=4, duration=1)
    ]

    #CHAMANDO A EXECUÇÃO SJF
    print("\nExecutando conexões por Shortest Job First (SJF)...")
    sjf_execution_order, sjf_avg_wait_time = run_sjf(dispositivos)

    #CHAMANDO A EXECUÇÃO POR PRIORIDADE
    print("\nExecutando conexões por (Prioridade)...")
    priority_execution_order, priority_avg_wait_time = run_priority(dispositivos)

    #PLOT DAS BARRAS PARA TEMPO MÉDIO DE ESPERA
    plt.figure(figsize=(10, 6))
    algoritmos = ['SJF', 'Prioridade']
    tempos_medios = [sjf_avg_wait_time, priority_avg_wait_time]
    plt.bar(algoritmos, tempos_medios, color=['blue', 'green'], alpha=0.6)
    plt.ylabel('Tempo Médio de Espera (s)')
    plt.title('Comparação de Tempo Médio de Espera entre SJF e Prioridade')

    #PLOTANDO A DIFERENÇA DE DESEMPENHO DO SJF PARA PRIORIDADE
    for i, tempo_medio in enumerate(tempos_medios):
        plt.text(i, tempo_medio * 1.01, f"{tempo_medio:.2f}", ha='center', va='bottom', fontsize=12)

    plt.ylim(0, max(sjf_avg_wait_time, priority_avg_wait_time) * 1.2)
    plt.grid(axis='y', linestyle='--', alpha=0.7)
    plt.show()
