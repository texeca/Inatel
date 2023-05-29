package RedesSociais;


public class Instagram extends RedeSocial{

    //Construtor do instagram
    public Instagram(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    //Método postar foto
    @Override
    public void postarFoto() {
        System.out.println("Postou uma foto no Instagram");
    }

    //Método postar vídeo
    @Override
    public void postarVideo() {
        System.out.println("Postou um vídeo no Instagram");
    }

    //Método postar comentario
    @Override
    public void postarComentario() {
        System.out.println("Postou um comentário no Instagram");
    }

    //Método curtir publicação
    @Override
    public void curtirPublicacao() {
        super.curtirPublicacao();
        System.out.print(" no Instagram");
    }
}
