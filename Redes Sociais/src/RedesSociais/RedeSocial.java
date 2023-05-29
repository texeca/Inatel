package RedesSociais;

public abstract class RedeSocial {

    //Atributos das redes sociais
    protected String senha;
    protected int numAmigos;

    //Construtor super das redes sociais
    public RedeSocial(String senha, int numAmigos) {
        this.senha = senha;
        this.numAmigos = numAmigos;
    }

    //Métodos abstrataos da redes sociais
    public abstract void postarFoto();
    public abstract void postarVideo();
    public abstract void postarComentario();

    //Método de curtida
    public void curtirPublicacao(){
        System.out.print("Curtiu uma publicação");
    }


}
