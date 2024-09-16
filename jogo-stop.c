#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_TAMANHO 100
#define MAX_JOGADORES 2
#define MAX_RODADAS 3
#define MAX_PALAVRAS 200
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
        "TUBARÃO"
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
        "BRASIL", 
        "ARGENTINA", 
        "CHILE", 
        "COLÔMBIA", 
        "URUGUAI", 
        "PERU", 
        "PARAGUAI", 
        "BOLÍVIA", 
        "VENEZUELA", 
        "EQUADOR",
        "CANADÁ", 
        "ESTADOS UNIDOS", 
        "FRANÇA", 
        "ALEMANHA", 
        "REINO UNIDO", 
        "JAPÃO", 
        "AUSTRÁLIA", 
        "ÍNDIA", 
        "CHINA", 
        "RÚSSIA",
        "ITÁLIA", 
        "ESPANHA", 
        "SUÉCIA", 
        "DINAMARCA", 
        "NORUEGA", 
        "SUÍÇA", 
        "ÁUSTRIA", 
        "BÉLGICA", 
        "HOLANDA", 
        "PORTUGAL",
        "SINGAPURA",
        "TAILÂNDIA", 
        "MÉXICO", 
        "NIGÉRIA", 
        "ÁFRICA DO SUL", 
        "SÉRVIA", 
        "EGITO", 
        "MALI",
        "ERITREIA",
        "SERRA LEOA",
        "ANGOLA",
        "JORDÂNIA", 
        "TURQUIA", 
        "ISRAEL",
        "IRAQUE",
        "SÍRIA", 
        "LÍBANO", 
        "PAQUISTÃO", 
        "SRI LANKA",
        "VATICANO", 
        "MALÁSIA", 
        "CUBA", 
        "PANAMÁ", 
        "NICARÁGUA",
        "HONDURAS",
        "GUATEMALA", 
        "EL SALVADOR", 
        "BELIZE", 
        "BRUNEI", 
        "LEBANON", 
        "MALAWI", 
        "LESOTO", 
        "COMORES", 
        "MAURÍCIO",
        "MALTA", 
        "MÔNACO", 
        "LUXEMBURGO", 
        "ESTÔNIA", 
        "LATVIA", 
        "LITUÂNIA",
        "ARMÊNIA", 
        "GEÓRGIA", 
        "BIELORRÚSSIA", 
        "KOSOVO",
        "MACEDÔNIA", 
        "ALBÂNIA", 
        "JAMAICA", 
        "BAHAMAS", 
        "BARBADOS", 
        "DOMINICA", 
        "SAINT LUCIA", 
        "BOLÍVIA", 
        "CINGAPURA", 
        "QUÊNIA",
        "MAURÍCIO", 
        "NEPAL", 
        "OMÃ", 
        "BOSNIA", 
        "SÃO TOMÉ E PRÍNCIPE", 
        "GUINÉ-BISSAU",
        "SAINT VINCENT", 
        "GÂMBIA", 
        "PAPUA-NOVA GUINÉ", 
        "MALAWI", //94
        "MARROCOS",
        "SEICHELES",
        "ETIÓPIA",
        "ZÂMBIA",
        "ZIMBÁBUE",
        "NOVA ZELÂNDIA"
    }
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
        "PORCHE"
    }
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
        "MILAN"
    }
};

int total_palavras_validas[MAX_CATEGORIAS] = {
    200,  // Frutas
    200,  // Animais
    200,  // Cores
    200,  // Objetos
    200,  // Profissões
    200,  // Países
    200,  // Carros
    200   // Times
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
                pontos[j] += calcularPontos(palGEavras, num_categorias);
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