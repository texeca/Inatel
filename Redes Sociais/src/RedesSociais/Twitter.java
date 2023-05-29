package RedesSociais;

import Interfaces.Compartilhamento;

public class Twitter extends RedeSocial implements Compartilhamento {

    //Construtor do twitter
    public Twitter(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    //Método postar foto
    @Override
    public void postarFoto() {
        System.out.println("Postou uma foto no Twitter");
    }

    //Método postar vídeo
    @Override
    public void postarVideo() {
        System.out.println("Postou um vídeo no Twitter");
    }

    //Método postar comentario
    @Override
    public void postarComentario() {
        System.out.println("Postou um comentário no Twitter");
    }

    //Método compartilhar
    @Override
    public void compartilhar() {
        System.out.println("Compartilhou algo no Twitter");
    }

    //Método curtir publicação
    @Override
    public void curtirPublicacao() {
        super.curtirPublicacao();
        System.out.print(" no Twitter");
    }
}
