import RedesSociais.RedeSocial;

public class Usuario {

    //Atributos do usuário
    private String nome;
    private String email;
    //Array de rede social
    RedeSocial[] redeSocial = new RedeSocial[20];

    //Construtor do usuário
    public Usuario(String nome, String email,RedeSocial[] redesSociais) {
        this.nome = nome;
        this.email = email;
        //Adicionado as redes sociais da main no array do usuário
        for (int i = 0; i < redesSociais.length; i++) {
            if(this.redeSocial[i] == null){
                this.redeSocial[i] = redesSociais[i];
            }
        }
    }

    //Getters do usuário
    public String getNome() {
        return nome;
    }
    public String getEmail() {
        return email;
    }

}
