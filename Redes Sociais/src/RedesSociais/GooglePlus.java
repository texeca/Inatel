package RedesSociais;

import Interfaces.Compartilhamento;
import Interfaces.VideoConferencia;

public class GooglePlus extends RedeSocial implements VideoConferencia, Compartilhamento {

    //Construtor do Googleplus
    public GooglePlus(String senha, int numAmigos) {
        super(senha, numAmigos);
    }

    //Método postar foto
    @Override
    public void postarFoto() {
        System.out.println("Postou um foto no GooglePlus");
    }

    //Método postar vídeo
    @Override
    public void postarVideo() {
        System.out.println("Postou um video no GooglePlus");
    }

    //Método postar comentario
    @Override
    public void postarComentario() {
        System.out.println("Postou um comentario no GooglePlus");
    }

    //Método compartilhar
    @Override
    public void compartilhar() {
        System.out.println("Compartilhou algo no GooglePlus");
    }

    //Método fazer streaming
    @Override
    public void fazStreaming() {
        System.out.println("Está fazendo um Streaming no GooglePlus");
    }

    //Método curtir publicação
    @Override
    public void curtirPublicacao() {
        super.curtirPublicacao();
        System.out.print(" no GooglePlus");
    }
}
