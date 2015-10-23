#include "../Header/Test.hpp"

/*void test(void)
{
    std::cout <<"\n\r" << "HelloWorld" << "\n\n\r";
}*/

/*Testing::Testing(void)
{
    
}*/

/**
 * Constructeur de la classe Testing
 * @param argc Nombre d'arguments lors de l'appel du programme
 * @param argv Liste des arguments lors de l'appel du programme
 */
Testing::Testing(int argc, char** argv) 
{
    nbArg = argc;
    listArg = argv;
    
    //On trouve la commande auto/load ou help en premier
    if(nbArg>1)
        for(int i = 0;(i<END_COMMAND_T)&&(cmd==END_COMMAND_T);i++)
        {    
            cout << listArg[1] << " vs " << command_list_t[i] << "\n\r";
            if(!strcmp(listArg[1],command_list_t[i]))
                cmd = (command_t)i;
        }
    
    // on execute le code selon le mode trouve
    switch (cmd) 
    {
        //Mode automatique
        case AUTO_SHORT:
        case AUTO_LONG:
            cout << "\n\r" << "Use automatic generated values" << "\n\n\r";
            AutoModeConfig();
            break;
        
        //Mode lecture de donnees
        case LOAD_SHORT:
        case LOAD_LONG:
            cout << "\n\r" << "Use values loaded from a file" << "\n\n\r";
            LoadModeConfig();
            break;
        
        // Mode aide
        case HELP_SHORT:
        case HELP_LONG:
            cout << "\n\r" << "Show help" << "\n\n\r";
            break;
        
        //Autre/erreurs
        default:
            cout << "\n\r" << "I AM ERROR" << "\n\n\r";
            break;
    }    
}

/**
 * Destructeur de Testing
 */
Testing::~Testing(void) 
{
    
}

/**
 * Fonction de configuration si le mode est automatique
 */
void Testing::AutoModeConfig(void)
{
    for(int j = 2; j < nbArg; j++)
    {    
        AutoModeOptionConfig(j);
    }
    cout << "\n\rN = " << N << " R = " << R << " D = " << D << "\n\r";
    cout << "OutputFile= " << outputFile << "\n\r";
}

/**
 * Fonction qui lit les differents paramètres necessaires 
 * pour generer les donnees automatiquement si ils sont
 * presents dans la liste d'argument
 * @param iDArg Numero du dernier argument lu 
 */
void Testing::AutoModeOptionConfig(int iDArg)
{
    option = END_OPTION_T;
        for(int i = 0;(i<END_OPTION_T)&&(option==END_OPTION_T);i++)
        {    
            cout << listArg[iDArg] << " vs " << option_list_t[i] << "\n\r";
            if(!strcmp(listArg[iDArg],option_list_t[i]))
            {    
                option = (option_t)i;
                
                switch(option)
                {
                    case NBR_DATA:
                        N = atoi(listArg[iDArg+1]);
                        break;
                        
                    case RANK_DATA:
                        R = atoi(listArg[iDArg+1]);
                        break;
                        
                    case DISPERTION_RATE:
                        D = atoi(listArg[iDArg+1]);
                        break;
                        
                    default :
                        break;
                }
            }   
        }
}

void Testing::LoadModeConfig(void)
{
    int count=0;
    if(nbArg==6)
    {
        cout << "\n\r" << "OK" << "\n\n\r";
        LoadT1(listArg[2]);
        LoadT2(listArg[3]);
        ResultTable = new int[K];
        
        for(int i = 0;(i<END_ALGO_T)&&(algo==END_ALGO_T);i++)
        {    
            cout << listArg[4] << " vs " << algo_list_t[i] << "\n\r";
            if(!strcmp(listArg[4],algo_list_t[i]))
                algo = (algo_t)i;
        }
        
        switch(algo)
        {
            case HASH_SHORT: 
            case HASH_LONG:
                cout << "\n\r" << "HASH TABLE" << "\n\n\r";
                
                break;
                
            case SEQ_SHORT: 
            case SEQ_LONG:
                cout << "\n\r" << "SEQ" << "\n\n\r";
                for(int i =0; i<K; i++)
                {
                    ResultTable[i] = RechercheSequentielle(DataTable,SearchTable[i],N);
                    if(ResultTable[i]!=-1)
                    {
                        count++;
                        printf("%i %i %i %i \n\n\r",count,i,SearchTable[i], ResultTable[i]);
                        
                    }
                }
                break;
                
            case BIN_SHORT:
            case BIN_LONG:
                cout << "\n\r" << "BINARY" << "\n\n\r";
                
                break;
        }

        for(int i =0;i<N;i++)
        {
            printf("%i ", DataTable[i]);
        }
        printf("\n\n\r");
;
    }
    else if(nbArg<6)
    {
        cout << "\n\r" << "Not enough argument" << "\n\n\r"; 
    }
    else
    {
        cout << "\n\r" << "Too much argument" << "\n\n\r";
    }
}

void Testing::LoadT1(const char* address)
{
    FILE * textfile;
    char c;
    int index=0;
    int tmp;
    string buffer="";
    
    textfile = fopen (address,"r");
    if (textfile == NULL) 
        perror ("Error opening file");
    else 
    {
        do 
        {
            c = fgetc (textfile);
            if(c != EOF)
            {
                if(c>='0'&& c<='9')
                {
                    buffer+=c;
                }
                else
                {
                    if(buffer!="")
                    {
                        sscanf(buffer.c_str(),"%i",&tmp); 
                        switch(index)
                        {
                            case 0 :
                                N = tmp;
                                DataTable = new int[tmp];
                                break;
                            case 1 :
                                R = tmp;
                                break;
                            case 2 :
                                D = tmp;
                                break;
                            default :
                                DataTable[index-3] = tmp;
                                break;
                        }
                        buffer="";
                        index++;
                    }    
                }
            }
            else
                if(buffer!="")
                {
                    sscanf(buffer.c_str(),"%i",&tmp);
                    DataTable[index-3] = tmp;
                }
        } 
        while (c != EOF);
    fclose (textfile);
    }
}

void Testing::LoadT2(const char* address)
{
    FILE * textfile;
    char c;
    int index=0;
    int tmp;
    string buffer="";
    
    textfile = fopen (address,"r");
    if (textfile == NULL) 
        perror ("Error opening file");
    else 
    {
        do 
        {
            c = fgetc (textfile);
            if(c != EOF)
            {
                if(c>='0'&& c<='9')
                {
                    buffer+=c;
                }
                else
                {
                    if(buffer!="")
                    {
                        sscanf(buffer.c_str(),"%i",&tmp); 
                        switch(index)
                        {
                            case 0 :
                                K = tmp;
                                SearchTable = new int[tmp];
                                break;
                   
                            default :
                                SearchTable[index-1] = tmp;
                                break;
                        }
                        buffer="";
                        index++;
                    }    
                }
            }
            else
                if(buffer!="")
                {
                    sscanf(buffer.c_str(),"%i",&tmp);
                    DataTable[index-3] = tmp;
                }
        } 
        while (c != EOF);
    fclose (textfile);
    }
}
