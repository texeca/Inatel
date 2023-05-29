package RedesSociais;
import Interfaces.Compartilhamento;
import Interfaces.VideoConferencia;

public class Facebook extends RedeSocial implements VideoConferencia,Compartilhamento {

    //Construtor do Facebook
    public Facebook(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    //Método compartilhar
    @Override
    public void compartilhar() {
        System.out.println("Compartilhou algo no Facebook");
    }

    //Método fazer streaming
    @Override
    public void fazStreaming() {
        System.out.println("Está fazendo um Streaming no Facebook");
    }

    //Método postar foto
    @Override
    public void postarFoto() {
        System.out.println("Postou uma foto no Facebook");
    }

    //Método postar comentario
    @Override
    public void postarComentario() {
        System.out.println("Postou um comentario no Facebook");
    }

    //Método postar vídeo
    @Override
    public void postarVideo() {
        System.out.println("Postou um vídeu no facebook");
    }

    //Método curtir publicação
    @Override
    public void curtirPublicacao() {
        super.curtirPublicacao();
        System.out.print(" no Facebook");
    }
}
