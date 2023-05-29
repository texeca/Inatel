import RedesSociais.*;

public class Main {
    public static void main(String[] args) {

        //C206 - A -> Redes Sociais

        //Instanciando as classes das redes sociais
        Facebook f1 = new Facebook("fc1524",15);
        GooglePlus g1 = new GooglePlus("ac65252",20);
        Twitter t1 = new Twitter("bc5177",10);
        Instagram i1 = new Instagram("bh8202",50);

        //Array de redes sociais
        RedeSocial[] redeSociais = new RedeSocial[10];
        //Adicionando 2 redes sociais
        redeSociais[0] = f1;
        redeSociais[1] = t1;

        //Criando usuário, com as redes sociais adicionadas
        Usuario us1 = new Usuario("Augusto","augusto_teixeira@gec.inatel.br",redeSociais);

        //Mostrando infos do usuário
        System.out.println("---- Infos do Usuario ----");
        System.out.println("Nome: " + us1.getNome());
        System.out.println("Email: " + us1.getEmail());

        //Usando os métodos das redes sociais que o usuário possui
        for (int i = 0; i < us1.redeSocial.length; i++) {

            //Métodos do facebook
            if (us1.redeSocial[i] instanceof Facebook) {
                ((Facebook) us1.redeSocial[i]).fazStreaming();
                us1.redeSocial[i].postarFoto();
                us1.redeSocial[i].curtirPublicacao();
                System.out.println("\n------------------");
            }

            //Métodos do googleplus
            if (us1.redeSocial[i] instanceof GooglePlus) {
                ((GooglePlus) us1.redeSocial[i]).compartilhar();
                ((GooglePlus) us1.redeSocial[i]).fazStreaming();
                us1.redeSocial[i].postarFoto();
                us1.redeSocial[i].postarComentario();
                us1.redeSocial[i].postarVideo();
                us1.redeSocial[i].curtirPublicacao();
                System.out.println("\n------------------");
            }

            //Métodos do twitter
            if (us1.redeSocial[i] instanceof Twitter) {
                ((Twitter) us1.redeSocial[i]).compartilhar();
                us1.redeSocial[i].postarComentario();
                us1.redeSocial[i].postarVideo();
                System.out.println("------------------");
            }

            //Métodos do instagram
            if (us1.redeSocial[i] instanceof Instagram) {
                us1.redeSocial[i].postarFoto();
                us1.redeSocial[i].postarComentario();
                us1.redeSocial[i].postarVideo();
                us1.redeSocial[i].curtirPublicacao();
                System.out.println("\n------------------");
            }
        }
    }
}