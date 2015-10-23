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
            //cout << listArg[1] << " vs " << command_list_t[i] << "\n\r";
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
    
}
