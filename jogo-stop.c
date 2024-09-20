#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAMANHO 100
#define MAX_JOGADORES 2
#define MAX_RODADAS 3
#define MAX_PALAVRAS 250
#define MAX_CATEGORIAS 10

const char *palavras_validas[MAX_CATEGORIAS][MAX_PALAVRAS] = {
    // Frutas
    {
        "MAÇÃ", 
        "BANANA", 
        "LARANJA", 
        "MANGA", 
        "UVA", 
        "PERA", 
        "ABACAXI", 
        "MELANCIA", 
        "KIWI", 
        "MORANGO",
        "FIGO", 
        "AMORA", 
        "COCO", 
        "ABACATE", 
        "JABUTICABA", 
        "CABELUDINHA", 
        "GRAVIOLA", 
        "TANGERINA", 
        "CAJÁ", 
        "FREI",
        "MANGABA", 
        "PITANGA", 
        "JACA", 
        "LICURI", 
        "GUANABANA", 
        "TAMARINDO", 
        "ROMÃ", 
        "PAPAYA", 
        "COCO-VERDE", 
        "NABO",
        "CAMPEÃO", 
        "ARATICUM", 
        "TAMARILLO", 
        "MAÇÃ-VERDE", 
        "LIMÃO", 
        "CAJU", 
        "GOIABA", 
        "NANGES", 
        "ABRICÓ", 
        "JAMELÃO",
        "TACACÁ", 
        "CABELUDO", 
        "GENGIBRE", 
        "MIRTILOS", 
        "CACAU", 
        "MACADÂMIA", 
        "COCO-BAIA", 
        "MANGA-ATAULFO", 
        "FENEL", 
        "ABRO",
        "QUINTO", 
        "JAGUAR", 
        "LIMEIRA", 
        "PLUM", 
        "PASSIFLORA", 
        "TAMARILLO", 
        "MORANGO-SILVESTRE", 
        "CAMOMILA", 
        "CUPUAÇU", 
        "FREI-MATE",
        "ACEROLA",
        "AMÊNDOA",
        "AMEIXA",
        "AVELÃ",
        "AÇAÍ",
        "BERGAMOTA",
        "CAJU",
        "CEREJA",
        "CAQUI",
        "DAMASCO",
        "FRAMBOESA",
        "GUARANÁ",
        "NOZ",
        "PÊSSEGO",
        "PITAIA",
        "TÂMARA"
    },
    // Animais
    {
        "CACHORRO", 
        "GATO", 
        "ELEFANTE", 
        "CAVALO", 
        "VACA", 
        "PATO", 
        "GALINHA", 
        "CABRA", 
        "OVELHA", 
        "MACACO",
        "TIGRE", 
        "URSO", 
        "LEÃO", 
        "RAPOSA", 
        "HIPOPÓTAMO", 
        "PEIXE", 
        "COELHO", 
        "CAVALO-MARINHO", 
        "AVESTRUZ", 
        "JAGUAR",
        "PANTERA", 
        "GIRAFA", 
        "GORILA", 
        "RINOCERONTE", 
        "ZEBRA", 
        "BÚFALO", 
        "BISONTE", 
        "PENGUIM", 
        "FALCÃO", 
        "ÁGUIA",
        "LAGARTO", 
        "PAVÃO", 
        "CASTOR", 
        "OURIÇO", 
        "CORNEL", 
        "CHIMPANZÉ", 
        "RATÃO", 
        "JABUTI", 
        "CARANGUEJO", 
        "PERCEVEJO",
        "MORCEGO", 
        "DONINHA", 
        "BALEIA", 
        "TONINHA", 
        "GRALHA", 
        "TAMANDUÁ", 
        "ORCA", 
        "ANDORINHA", 
        "GOLFINHO", 
        "SIRI",
        "PANGOLIM", 
        "MARTINHA", 
        "CUCUJÃO", 
        "DROMEDÁRIO", 
        "CROCODILO", 
        "LAGOSTA", 
        "PIRANHA", 
        "PÁSSARO",
        "PAPAGAIO",
        "ANACONDA", 
        "CAMELO", 
        "COALA",
        "URSO-PANDA", 
        "JAGUATIRICA", 
        "RINOCERONTE-INDIANO", 
        "MANATÍ", 
        "LEÃO-MARINHO", 
        "FURÃO", 
        "BESOURO", 
        "RATAZANA", 
        "REI", 
        "TAPIR",
        "ESTRELA-DO-MAR",
        "CAMARÃO",
        "TOPEIRA",
        "LEBRE",
        "POLVO",
        "ABUTRE",
        "ALCE",
        "ARARA",
        "ANDORINHA", 
        "BEIJA-FLOR",
        "BARATA",
        "BORBOLETA",
        "CAPIVARA",
        "CAMUNDONGO",
        "CHINCHILA",
        "DODÔ",
        "DONINHA",
        "DRAGÃO-DE-KOMODO",
        "DIABO-DA-TASMÂNIA", 
        "ESCORPIÃO",
        "ENGUIA",
        "FLAMINGO",
        "FORMIGA",
        "FOCA",
        "GRILO",
        "GUAXINIM",
        "GAIVOTA",
        "GALO",
        "GAMBÁ",
        "HAMSTER",
        "IGUANA",
        "JOANINHA",
        "JIBOIA",
        "JACARÉ",
        "KIWI",
        "LOBO",
        "LEOPARDO", 
        "LÊMURE",
        "LARGATIXA",
        "MINHOCA",
        "MARIPOSA",
        "MOSQUITO",
        "OSTRA",
        "ORNITORRINCO",
        "ONÇA",
        "PORCO",
        "PORCO-ESPINHO", 
        "PICA-PAU",
        "PORQUINHO-DA-ÍNDIA",
        "QUERO-QUERO",
        "TARTARUGA",
        "TATU",
        "TOUPEIRA",
        "TUBARÃO",
        "HARPIA"
    },
    // Cores
    {
        "AZUL", 
        "VERMELHO", 
        "VERDE", 
        "AMARELO", 
        "ROSA",
        "PRETO", 
        "BRANCO", 
        "CINZA", 
        "ROXO", 
        "LARANJA",
        "BEGE", 
        "MARROM", 
        "PRATA", 
        "OURO", 
        "CREME", 
        "CARAMELO", 
        "AZUL-CLARO", 
        "AZUL-ESCURO", 
        "VERDE-OLIVA", 
        "VERDE-LIMÃO",
        "VIOLETA", 
        "SALMÃO", 
        "AÇAFRÃO", 
        "TURQUESA", 
        "LILÁS", 
        "CINZA-CLARO", 
        "CINZA-ESCURO", 
        "MARELO-OURO", 
        "AZUL-TURQUESA", 
        "MAUVE",
        "CARMINA", 
        "MAGENTA", 
        "AQUA", 
        "LILÁS", 
        "CINZA-PRATA", 
        "BORGONHA", 
        "AZUL-ROYAL", 
        "MEL", 
        "SARGENTINO", 
        "MANTEIGA",
        "OLIVA", 
        "AZUL-BEBÊ", 
        "CAQUI", 
        "VERDE-ESMERALDA", 
        "TERRA", 
        "ROSA-CHOQUE", 
        "MORANGO", 
        "VINO", 
        "DOURADO", 
        "MARFIM",
        "CARAMELIZADO", 
        "SÚDESTE", 
        "FRESCO", 
        "CLARO", 
        "ESCURRO", 
        "TERRACOTA", 
        "JADE", 
        "SAFIRA", 
        "ÁRTICO", 
        "FUMÊ",
        "AVENTURINA", 
        "VERDE-AGUA", 
        "FENDA", 
        "BORDEAUX", 
        "AZUL-BABY", 
        "MAUVE", 
        "GEL", 
        "MATTE", 
        "GRAFITE", 
        "CRISTAL",
        "OCEANO", 
        "DOURADO-MATE", 
        "AZUL-POLO", 
        "AZUL-TURQUESA", 
        "LAGUNA", 
        "CINZA-ESCOVADO", 
        "GELADEIRA", 
        "INFINITO", 
        "ALABASTRO", 
        "PASTEL"
    },
    // Objetos
    {
        "MESA", 
        "CADEIRA", 
        "TELEVISÃO", 
        "SOFÁ", 
        "LÂMPADA", 
        "PORTA", 
        "JANELA", 
        "CARRO", 
        "CELULAR", 
        "CONTROLE",
        "COMPUTADOR",
        "BRINCO",
        "LIVRO",
        "RELÓGIO", 
        "ESCRITÓRIO", 
        "GELADEIRA", 
        "ARMÁRIO", 
        "CAMA", 
        "PAPEL", 
        "CANETA", 
        "MOCHILA", 
        "FERRAMENTA",
        "COMPUTADOR",
        "FONE", 
        "TAPETE", 
        "PAPELÃO", 
        "QUADRO", 
        "TOALHA", 
        "PANELA", 
        "FOGÃO", 
        "VENTILADOR",
        "SECADOR",
        "TÁBUA",
        "JOGO", 
        "TECLADO", 
        "RÁDIO", 
        "TELEFONE", 
        "MICRO-ONDAS", 
        "RELÓGIO-ALARM",
        "CARTÃO", 
        "GARRAFA", 
        "CARTUCHO", 
        "ARMÁRIO",
        "CARTÃO-PRESENTE", 
        "FOTOGRAFIA", 
        "TELEVISÃO", 
        "PROJETOR", 
        "SECADOR-DE-CABELO", 
        "ENTRADA", 
        "IMPRESSORA", 
        "TELEFONE-COMERCIAL",
        "SILICONE", 
        "BRINDE", 
        "ADESIVO", 
        "CARTAZ", 
        "ALMOFADA", 
        "CANECA", 
        "PARA-LAMA", 
        "CABIDE", 
        "PORTA-RETRATO", 
        "CARTUCHO",
        "AEROSSOL",
        "RIPPA", 
        "ANEXO", 
        "CARRINHO", 
        "PLACA", 
        "TAPETE", 
        "AQUECEDOR", 
        "SACA-ROLHAS", 
        "TROFÉU", 
        "CANUDO",
        "REVESTIMENTO", 
        "CONJUNTO", 
        "SUPORTE", 
        "CAIXA", 
        "ROUPA", 
        "PORTA-LUVA",
        "QUADRO-NEGRO", 
        "COPO",
        "REFRIGERADOR", 
        "CARTÃO-DE-CRÉDITO", 
        "CARTÃO-DE-DÉBITO",
        "ACESSÓRIOS",
        "POTE"
    },
    // Profissões
    {
        "MÉDICO", 
        "ENFERMEIRO", 
        "ADVOGADO", 
        "ENGENHEIRO", 
        "ARQUITETO", 
        "PROFESSOR", 
        "CABELEIREIRO", 
        "PINTOR", 
        "MECÂNICO", 
        "YOUTUBER"
        "COZINHEIRO",
        "JORNALISTA", 
        "FOTÓGRAFO", 
        "DESENHISTA", 
        "RECEPCIONISTA", 
        "VENDEDOR", 
        "JUIZ", 
        "DENTISTA", 
        "BIÓLOGO", 
        "CARTÓGRAFO", 
        "PSICÓLOGO",
        "ARTESÃO", 
        "SOLDADOR", 
        "MOTORISTA", 
        "PARAMÉDICO", 
        "NUTRICIONISTA", 
        "ASSISTENTE SOCIAL", 
        "TÉCNICO", 
        "ANALISTA", 
        "MONTADOR", 
        "AGENTE DE VIAGENS",
        "ARQUEÓLOGO", 
        "TÉCNICO EM INFORMÁTICA", 
        "BOMBEIRO", 
        "ENTREVISTADOR", 
        "MAESTRO", 
        "PESQUISADOR", 
        "DIRETOR", 
        "PRODUZIDOR", 
        "GERENTE", 
        "ZOOLOGISTA",
        "BIOQUÍMICO", 
        "HISTORIADOR", 
        "REVISOR", 
        "TÉCNICO EM RADIOLOGIA", 
        "PALEONTÓLOGO", 
        "QUÍMICO", 
        "ANIMADOR", 
        "TÉCNICO EM ENFERMAGEM", 
        "ASSISTENTE ADMINISTRATIVO",
        "CONTADOR", 
        "ESCRITOR", 
        "ARTISTA", 
        "JORNALISTA", 
        "CINEMATOGRÁFO", 
        "COORDENADOR",
        "DIRETOR DE ARTE", 
        "TÉCNICO",
        "LOCUTOR", 
        "GESTOR", "TRADUTOR",
        "MESTRE DE CERIMÔNIA", 
        "CORRETOR", 
        "ASSISTENTE DE DIREÇÃO", 
        "CAPITÃO", "CONSELHEIRO", 
        "TREINADOR", 
        "ANALISTA DE SISTEMAS", 
        "EDITORA", 
        "REDATOR"
    },
    // Países
    {
        "Argentina",
        "Honduras",
        "Bolívia",
        "México",
        "Brasil",
        "Nicarágua",
        "Chile",
        "Panamá",
        "Colômbia",
        "Paraguai",
        "Costa Rica",
        "Perú",
        "Equador",
        "Uruguai",
        "El Salvador",
        "Venezuela",
        "Guatemala",
        "Afeganistão",
        "Maldivas",
        "Bangladesh",
        "Mongólia",
        "Butão",
        "Mianmar",
        "Camboja",
        "Nepal",
        "China",
        "Paquistão",
        "Índia",
        "Filipinas",
        "Indonésia",
        "Sri Lanka",
        "Laos",
        "Tailândia",
        "Malásia",
        "Vietname",
        "Cazaquistão",
        "Quirguizistão",
        "Tajiquistão",
        "Turquemenistão",
        "Usbequistão",
        "Iémen",
        "Irão",
        "Iraque",
        "Angola",
        "Madagáscar",
        "Bením",
        "Malawi",
        "Botsuana",
        "Mali",
        "Burkina Faso",
        "Maurícias",
        "Burundi",
        "Mauritânia",
        "Camarões",
        "Moçambique",
        "Cabo Verde",
        "Namíbia",
        "África do Sul",
        "Níger",
        "Chade",
        "Nigéria",
        "Comores",
        "Ruanda",
        "Congo",
        "São Tomé e Príncipe",
        "Senegal",
        "Jibuti",
        "Seicheles",
        "Guiné Equatorial",
        "Serra Leoa",
        "Eritreia",
        "Somália",
        "Etiópia",
        "Sudáfrica",
        "Gabão",
        "Sul do Sudão",
        "Gâmbia",
        "Sudão",
        "Gana",
        "Suazilândia",
        "Guiné-Bissau",
        "Tanzânia",
        "GuinéTogo",
        "Costa de marfil",
        "Uganda",
        "Quénia",
        "Zâmbia",
        "Lesoto",
        "Zimbabué",
        "Libéria",
        "Ilhas Cook",
        "Timor-Lestre",
        "Fiji",
        "Quiribáti",
        "Ilhas Marshall",
        "Micronésia",
        "Nauru",
        "Niue",
        "Palau",
        "Papua Nova Guiné",
        "Samoa",
        "Ilhas Salomão",
        "Tonga",
        "Tuvalu",
        "Vanuatu",
        "Aruba",
        "Montserrat",
        "Anguilla",
        "Nova Caledónia",
        "Bonaire",
        "Pitcairn",
        "Curaçau",
        "Santo Eustáquio",
        "Ilhas Falkland",
        "São Martinho",
        "Polinésia Francesa",
        "São Pedro e Miquelão",
        "Saba",
        "Ilhas Turcas e Caicos",
        "Maiote",
        "Wallis et Futuna",
        "República da Albânia",
        "Bósnia-Herzegovina",
        "Kosovo",
        "Montenegro",
        "República da Macedônia do Norte",
        "República da Sérvia",
        "Turquia",
        "Algéria",
        "Arménia",
        "Azerbaijão",
        "Bielorrússia",
        "Egito",
        "Geórgia",
        "Israel",
        "Jordânia",
        "Líbano",
        "Libia",
        "Moldávia",
        "Marrocos",
        "Palestina",
        "Siria",
        "Tunísia",
        "Ucrânia"
    },
    //Carros
    {
        "ALFA ROMEO",
        "AUDI",
        "BMW",
        "CHAMONIX",
        "CHERY",
        "CIELO",
        "CHEVROLET",
        "CAMARO",
        "CELTA",
        "CORSA",
        "CORSA SEDAN",
        "CORSA PICK UP",
        "CHEVY",
        "ONIX",
        "OPALA",
        "OPALA COUPÉ",
        "AIRCROSS",
        "FIAT",
        "ARGO",
        "CITY",
        "MOBI",
        "PALIO",
        "UNO",
        "FORD",
        "FIESTA",
        "ECOSPORT",
        "JEEP",
        "MUSTANG",
        "HONDA",
        "CIVIC",
        "FIT",
        "HYUNDAI",
        "HB20",
        "HB20S",
        "HB20X",
        "HYUNDAI ATOS",
        "VOGUE",
        "MERCEDES",
        "MINI COOPER",
        "TESLA",
        "MITSUBISHI",
        "NISSAN",
        "VERSA",
        "PEUGEOT",
        "RENAUT",
        "CLIO",
        "CLIO SEDAN",
        "KWID",
        "LOGAN",
        "SANDERO",
        "SUZUKI",
        "TOYOTA",
        "HILUX",
        "VOLVO",
        "VOLKSWAGEN",
        "GOL",
        "FOX",
        "FUSCA",
        "KOMBI",
        "SUV",
        "GOLF",
        "POLO",
        "POLO SEDAN",
        "POLO CLASSIC",
        "FERRARI",
        "PORCHE",
        "DODGE",
        "LAMBORGHINI"
    },
    //Times
    {
        "VASCO",
        "CRUZEIRO",
        "SÃO PAULO",
        "FLAMENGO",
        "SANTOS",
        "CORINTHIANS",
        "YPIRANGA",
        "AMAZONAS",
        "BAHIA",
        "VITÓRIA",
        "ATLÉTICO MINEIRO",
        "ATLÉICO",
        "ATLÉTICO PARANAENSE",
        "FLUMINENSE",
        "CEARÁ",
        "FORTALEZA",
        "BOTAFOGO",
        "GOIÁS",
        "GRÊMIO",
        "CHAPECOENSE",
        "AMÉRICA",
        "CUIABÁ",
        "JUVENTUDE",
        "BRAGANTINO",
        "PAYSANDU",
        "BARCELONA",
        "REAL MADRID",
        "MIRASSOL",
        "PALMEIRAS",
        "CORITIBA",
        "ATLÉTICO-PR",
        "ATLÉTICO-MG",
        "MANCHESTER CITY",
        "LIVERPOOL",
        "CHELSEA",
        "MILAN",
        "WEST HAM UNITED"
    }
};

int total_palavras_validas[MAX_CATEGORIAS] = {
    250,  // Frutas
    250,  // Animais
    250,  // Cores
    250,  // Objetos
    250,  // Profissões
    250,  // Países
    250,  // Carros
    250   // Times
};

void limparBuffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int palavraValida(const char *categoria, const char *palavra, int num_categorias, const char categorias[][MAX_TAMANHO]) {
    for (int i = 0; i < num_categorias; i++) {
        if (strcasecmp(categorias[i], categoria) == 0) {
            for (int j = 0; j < total_palavras_validas[i]; j++) {
                if (strcasecmp(palavra, palavras_validas[i][j]) == 0) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int calcularPontos(char palavras[MAX_JOGADORES][MAX_CATEGORIAS][MAX_TAMANHO], int num_categorias) {
    int pontos = 0;
    for (int i = 0; i < num_categorias; i++) {
        int palavraValida = 0;
        int palavraUnica = 1;
        for (int j = 0; j < MAX_JOGADORES; j++) {
            if (strlen(palavras[j][i]) > 0) {
                palavraValida = 1;
                for (int k = j + 1; k < MAX_JOGADORES; k++) {
                    if (strcasecmp(palavras[j][i], palavras[k][i]) == 0) {
                        palavraUnica = 0;  
                    }
                }
            }
        }
        if (palavraValida) {
            pontos += (palavraUnica) ? 10 : 5;  
        }
    }
    return pontos;
}

void jogarStop() {
    char categorias_selecionadas[MAX_CATEGORIAS][MAX_TAMANHO];
    char palavras[MAX_JOGADORES][MAX_CATEGORIAS][MAX_TAMANHO];
    char letra;
    int pontos[MAX_JOGADORES] = {0};
    int num_categorias, i, j, rodada;
    int jogar_novamente;

    do {
        printf("Bem-vindo ao jogo de Stop!\n");

        printf("Digite o número de categorias (máximo %d): ", MAX_CATEGORIAS);
        scanf("%d", &num_categorias);
        while (num_categorias < 1 || num_categorias > MAX_CATEGORIAS) {
            printf("Número de categorias inválido. Digite um número entre 1 e %d: ", MAX_CATEGORIAS);
            scanf("%d", &num_categorias);
        }
        limparBuffer();

        printf("Digite %d categorias:\n", num_categorias);
        for (i = 0; i < num_categorias; i++) {
            printf("Categoria %d: ", i + 1);
            fgets(categorias_selecionadas[i], MAX_TAMANHO, stdin);
            categorias_selecionadas[i][strcspn(categorias_selecionadas[i], "\n")] = '\0'; 
        }

        for (rodada = 1; rodada <= MAX_RODADAS; rodada++) {
            printf("\nRodada %d\n", rodada);
            printf("Digite uma letra para começar a rodada: ");
            scanf(" %c", &letra);
            letra = toupper(letra);
            limparBuffer();

            for (j = 0; j < MAX_JOGADORES; j++) {
                printf("\nJogador %d, agora é a sua vez:\n", j + 1);

                for (i = 0; i < num_categorias; i++) {
                    while (1) {
                        printf("%s: ", categorias_selecionadas[i]);
                        fgets(palavras[j][i], MAX_TAMANHO, stdin);
                        palavras[j][i][strcspn(palavras[j][i], "\n")] = '\0'; 

                        if (palavraValida(categorias_selecionadas[i], palavras[j][i], num_categorias, categorias_selecionadas)) {
                            break;  
                        } else {
                            printf("Palavra inválida ou não pertence à categoria. Tente novamente.\n");
                        }
                    }
                }
            }
            
            for (j = 0; j < MAX_JOGADORES; j++) {
                pontos[j] += calcularPontos(palavras, num_categorias);
            }
        }

        printf("\nFim do jogo! Pontuação final:\n");
        for (j = 0; j < MAX_JOGADORES; j++) {
            printf("Jogador %d: %d pontos\n", j + 1, pontos[j]);
        }

        printf("\nDeseja jogar novamente? Digite 1 para sim ou 0 para não: ");
        scanf("%d", &jogar_novamente);
        limparBuffer();
        
        memset(pontos, 0, sizeof(pontos));
        memset(palavras, 0, sizeof(palavras));

    } while (jogar_novamente == 1);

    printf("Obrigado por jogar!\n");
}

int main() {
    jogarStop();
    return 0;
}
