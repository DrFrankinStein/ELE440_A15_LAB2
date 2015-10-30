#include <vector>

#include "../Header/Test.hpp"

/**
 * Constructeur de Testing
 */
Testing::Testing(void)
{
    barometrePrep.instructions=0;
    barometreRech.instructions=0;
}

/**
 * Destructeur de Testing
 */
Testing::~Testing(void) 
{
    
}

/**
 * Charge le fichier de donnees
 * @param address Adresse du fichier de donnees
 * @return True si le fichier est valide
 */
bool Testing::LoadT1(const char* address)
{
    FILE * textfile;
    char c;
    int index=0;
    int tmp;
    string buffer="";
    
    textfile = fopen (address,"r");
    if (textfile == NULL) 
    {
        perror ("Error opening file");
        return false;
    }
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
    return true;
}

/**
 * Charge le fichier de donnees a rechercher
 * @param address Adresse du fichier a charger
 * @return True si le fichier est valide
 */
bool Testing::LoadT2(const char* address)
{
    FILE * textfile;
    char c;
    int index=0;
    int tmp;
    string buffer="";
    
    textfile = fopen (address,"r");
    if (textfile == NULL)
    {
        perror ("Error opening file");
        return false;
    }
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
                    SearchTable[index-1] = tmp;
                }
        } 
        while (c != EOF);
    fclose (textfile);
    }
    return true;
}

/**
 * Sauvegarder les resultats et statistiques dans un fichier
 * @param address Nom du fichier a creer
 */
void Testing::SaveT3(const char* address)
{
    FILE * textfile;
    string alg;  
    textfile = fopen (address,"w");
    
    if(textfile)
    {
        
        switch(algo)
        {
            case HASH_SHORT: 
            case HASH_LONG:
            {    
                alg = "Table de hachage";
            }    
            break;
                
            case TREE_SHORT: 
            case TREE_LONG:
            {
                alg = "Arbre Binaire";
            }
            break;    
                
            case SEQ_SHORT: 
            case SEQ_LONG:
            {
                alg = "Recherche sequencielle";
            }
            break;
                
            case BIN_SHORT:
            case BIN_LONG:
            {    
                alg = "Recherche binaire";
            }
            break;
            
            case OPTIMIZE_SHORT:
            case OPTIMIZE_LONG:
            {
                alg = "Recherche optimisee";
            }    
            break;
        }
        //Stats methodeTri
        fprintf(textfile,"Algorithme de recherche = %s\nAlgorithme de tri = %s\n\n",alg.c_str(),methodeTri.c_str());
        fprintf(textfile,"N=%i\nR=%i\nD=%i\n\n",N,R,D);
        fprintf(textfile,"K=%i\nNBRE DE DONNEES TROUVEES = %i\n\n",K,count);
        fprintf(textfile,"Tp= %llu\nTr= %llu\n",barometrePrep.instructions,barometreRech.instructions); 
        fprintf(textfile,"Tt= %llu\nTa= %llu\n\n",barometrePrep.instructions+barometreRech.instructions,(barometrePrep.instructions+barometreRech.instructions)/K);
        //T1
        for(int i =0; i<(N-1);i++)
            fprintf(textfile,"%i\t",DataTable[i]);
        fprintf(textfile,"%i\n\n",DataTable[N-1]);
        //T2
        for(int i =0; i<(K-1);i++)
            fprintf(textfile,"%i\t",SearchTable[i]);
        fprintf(textfile,"%i\n\n",SearchTable[K-1]);
        //T3
        for(int i =0; i<(K-1);i++)
            fprintf(textfile,"%i\t",ResultTable[i]);
        fprintf(textfile,"%i",ResultTable[K-1]);    
    }
    
    fclose(textfile);
}

/**
 * Permet d'afficher les statistiques a l'ecran
 */
void Testing::ShowStats(void)
{
    string alg;
    switch(algo)
    {
        case HASH_SHORT: 
        case HASH_LONG:
        {    
            alg = "Table de hachage";
        }    
        break;

        case TREE_SHORT: 
        case TREE_LONG:
        {
            alg = "Arbre Binaire";
        }
        break;    

        case SEQ_SHORT: 
        case SEQ_LONG:
        {
            alg = "Recherche sequencielle";
        }
        break;

        case BIN_SHORT:
        case BIN_LONG:
        {    
            alg = "Recherche binaire";
        }
        break;

        case OPTIMIZE_SHORT:
        case OPTIMIZE_LONG:
        {
            alg = "Recherche optimisee";
        }    
        break;
    }
    //Stats methodeTri
    printf("\n\rAlgorithme de recherche = %s\n\rAlgorithme de tri = %s\n\n\r",alg.c_str(),methodeTri.c_str());
    printf("N=%i\n\rR=%i\n\rD=%i\n\n\r",N,R,D);
    printf("K=%i\n\rNBRE DE DONNEES TROUVEES = %i\n\n\r",K,count);
    printf("Tp= %llu\n\rTr= %llu\n\r",barometrePrep.instructions,barometreRech.instructions); 
    printf("Tt= %llu\n\rTa= %llu\n\n\r",barometrePrep.instructions+barometreRech.instructions,(barometrePrep.instructions+barometreRech.instructions)/K);
}

/**
 * Fonction a appeler pour configurer les tests
 */
void Testing::EnterConfig(void)
{
    SetData();
    SetSearch();
    SetOutputFileAddress();
    SetAlgo();  
}

/**
 * Configure comment les donnees sont chargees
 */
void Testing::SetData(void)
{
    char c;
    bool exit =false;
    while(!exit)
    {
        cout << "Enter the type of data to test(0=auto; 1=load): ";
        cin >> c;
        if(cin.good())
        {
            switch(c)
            {
                case '0':
                    cmd = AUTO_SHORT;
                    SetNRD();
                    exit = true;
                    break;
                case '1':
                    cmd = LOAD_SHORT;
                    SetDataFileAddress();
                    exit = true;
                    break;
                default :
                    cout << "Wrong input\n\r";
                    break;
            }
        }
        else
        {
            cout << "Wrong input\n\r";
        }
        cin.ignore();
        cin.clear();
    }    
}

/**
 * Configure N, R et D
 */
void Testing::SetNRD(void)
{
    int value;
    bool exit;
    
    cout << "Enter auto config variable\n\r";
    for(int i=0; i<3;i++)
    {    
        switch(i)
        {
            case 0 :
                cout << "N = ";
                break;
            case 1 :
                cout << "R = ";
                break;
            case 2 :
                cout << "D = ";
                break;
                
        }
        exit = false;
        while(!exit)
        {
            cin >> value;
            if(cin.good())
            {
                if(value>=0)
                {
                    switch(i)
                    {
                        case 0 :
                        {
                            if(value>=1)
                            {
                                N = value;
                                exit = true;
                            }
                            else
                                cout << "Wrong value (N must be greater than 0)\n\rN= ";
                                
                        }
                            break;
                        case 1 :
                        {
                            if(value>=N)
                            {
                                R = value;
                                exit = true;
                            }
                            else    
                                cout << "Wrong value (R must be equal or greater than N)\n\rR= ";
                        }
                            break;
                        case 2 :
                        {
                            if(value<=100)
                            {
                                D = value;
                                exit = true;
                            }   
                            else
                                cout << "Wrong value (D must be between 0 and 100)\n\rD= ";
                        }
                            break;
                    }  
                }
                else
                {
                    cout << "Wrong value (must be greater or equal to 0)\n\r";
                }
            }
            else
            {
                cout << "Wrong value (must be a valid integer)\n\r";
                cin.clear();
                cin.ignore();
            }
                   
        }
    }
    cout << "N = " << N << " R = " << R << " D = " << D << endl;
    //Generate Values
    DataTable = new int[N];
    GenererDonnees(DataTable, N , R, D);
}


void Testing::SetDataFileAddress(void)
{
    string str;
    bool exit =false;
    while(!exit)
    {
        cout << "Enter the address of the data file: ";
        cin >> str;
        if(cin.good())
        {
            if(LoadT1(str.c_str()))
            {
                cout << "N = " << N << " R = " << R << " D = " << D << endl;
                exit = true;
            }
        }
        else
        {
            cout << "Wrong input\n\r";
            cin.clear();
            cin.ignore();
        }
    }
}

void Testing::SetSearch(void)
{
    char c;
    bool exit =false;
    while(!exit)
    {
        cout << "Enter the type of search to use (0=manual; 1=load): ";
        cin >> c;
        if(cin.good())
        {
            switch(c)
            {
                case '0':
                    if(cmd==AUTO_SHORT)
                        cmd = MANUAL_AUTO_SHORT;
                    else
                        cmd = MANUAL_LOAD_SHORT;
                    exit = true;
                    break;
                case '1':
                    SetSearchFileAddress();
                    exit = true;
                    break;
                default :
                    cout << "Wrong input\n\r";
                    break;
            }
        }
        else
        {
            cout << "Wrong input\n\r";
        }
        cin.clear();
        cin.ignore();
    }
}

/**
 * Mettre l'adresse pour le fichier des requetes
 */
void Testing::SetSearchFileAddress(void)
{
    string str;
    bool exit =false;
    while(!exit)
    {
        cout << "Enter the address of the search file: ";
        cin >> str;
        if(cin.good())
        {
            if(LoadT2(str.c_str()))
            {
                cout << "K = " << K << endl;
                ResultTable = new int[K];
                exit = true;
            }
        }
        else
        {
            cout << "Wrong input\n\r";
        }
    }
}

/**
 * Mettre l'adresse du fichier des statistiques a creer/modifier
 */
void Testing::SetOutputFileAddress(void)
{
    string str;
    bool exit =false;
    while(!exit)
    {
        cout << "Enter the address of the stats file: ";
        cin >> str;
        if(cin.good())
        {
            outputFile=str;
            exit = true;
        }
        else
        {
            cout << "Wrong input\n\r";
        }
    }
}

/**
 * Choix de l'algorithme
 */
void Testing::SetAlgo(void)
{
    char c;
    bool exit =false;
    while(!exit)
    {
        cout << "Enter the type of algorithm to use :\n\r";
        cout << "0=sequencial" << endl;
        cout << "1=hash table" << endl;
        cout << "2=binary" << endl;
        cout << "3=tree" << endl;
        cout << "4=optimized" << endl;
        cin >> c;
        if(cin.good())
        {
            switch(c)
            {
                case '0':
                    algo =SEQ_SHORT;
                    exit = true;
                    break;
                case '1':
                    algo = HASH_SHORT;
                    exit = true;
                    break;
                case '2':
                    algo = BIN_SHORT;
                    exit = true;
                    break;
                case '3':
                    algo = TREE_SHORT;
                    exit = true;
                    break;
                case '4':
                    algo = OPTIMIZE_SHORT;
                    exit = true;
                    break;
                default :
                    cout << "Wrong input\n\r";
                    break;
            }
        }
        else
        {
            cout << "Wrong input\n\r";
        }
        cin.clear();
        cin.ignore();
    }
}

/**
 * Demarrer le test
 */
void Testing::StartTest(void)
{
    switch(cmd)
    {
        case AUTO_SHORT:
        case LOAD_SHORT:
            AutoRequest();
            break;
            
        case MANUAL_AUTO_SHORT:
        case MANUAL_LOAD_SHORT:
            ManualRequest();
            break;
    }
}

/**
 * Si les requêtes viennent d'un fichier 
 */
void Testing::AutoRequest(void)
{
    count=0;
    switch(algo)
    {
        case HASH_SHORT: 
        case HASH_LONG:
        {    
            hashH hashy(N);
            for(int i = 0; i < N; i++)
            {
                hashy.AddItem(DataTable[i],i);
            }
            barometrePrep.instructions = hashy.RetourneBarometreInstructions();
            for(int i =0; i<K; i++)
            {
                ResultTable[i] = hashy.RechercheHash(SearchTable[i]);
                if(ResultTable[i]!=-1)
                    count++;
            }
            barometreRech.instructions = hashy.RetourneBarometreInstructions();
        }    
        break;

        case TREE_SHORT: 
        case TREE_LONG:
        {
            BinaryTree bin;
            for(int i =0; i<N; i++)
            {
                bin.addnode(DataTable[i],i);
            }
            barometrePrep.instructions=bin.RetourneBarometreInstructions();
            for(int i =0; i<K; i++)
            {
                ResultTable[i] = bin.findNode(SearchTable[i]);
                if(ResultTable[i]!=-1)
                    count++;
            }
            barometreRech.instructions = bin.RetourneBarometreInstructions();
        }

        break;    

        case SEQ_SHORT: 
        case SEQ_LONG:
        {
            for(int i =0; i<K; i++)
            {
                ResultTable[i] = RechercheSequentielle(DataTable,SearchTable[i],N,barometreRech);
                if(ResultTable[i]!=-1)
                    count++;
            }
        }
        break;

        case BIN_SHORT:
        case BIN_LONG:
        {    
            int BigDataTable[N][2];
            int i;
            for (i = 0; i < N; i++)
            {
                barometrePrep.instructions++;
                BigDataTable[i][0] = DataTable[i]; // Premiere rangee = cle
                BigDataTable[i][1] = i; // Deuxieme rangee = position dans la liste non triee
            }

            if(D==0 || (D<5 && N<2000))
            {
                methodeTri = "Tri par Insertion";
                barometrePrep.instructions+=TriParInsertion(BigDataTable,N).instructions;
            }
            else if(R<1000000)
            {
                int nbChiffre;
                nbChiffre=(int)log10(R)+1;
                methodeTri = "Tri par Base";
                barometrePrep.instructions+=TriParBase(BigDataTable,N,nbChiffre).instructions;
            }
            else
            {
                methodeTri = "Tri par Fusion";
                barometrePrep.instructions+=TriParFusion(BigDataTable, 0, N-1).instructions;
            }

            for(int i =0; i<K; i++)
            {
                ResultTable[i] = RechercheBinaire(BigDataTable,SearchTable[i],N,barometreRech);
                if(ResultTable[i]!=-1)
                    count++;
            }
        }
        break;
        case OPTIMIZE_SHORT:
        case OPTIMIZE_LONG:
        {
            barometrePrep.instructions = InitRechercheOptimisee(DataTable,N, R, D, &methodeTri).instructions;
            for(int i =0; i<K; i++)
            {
                ResultTable[i] = RechercheOptimisee(DataTable,SearchTable[i],N, R, D,barometreRech);
                if(ResultTable[i]!=-1)
                    count++;
            }
        }  
    }
    ShowStats();
    SaveT3(outputFile.c_str());
}

/**
 * Si les requêtes sont entrees manuellement
 */
void Testing::ManualRequest(void)
{
    int value = 0;
    K=0;
    count=0;
    vector<int> search;
    vector<int> result;
    
    switch(algo)
    {
        case HASH_SHORT: 
        case HASH_LONG:
        {    
            hashH hashy(N);
            for(int i = 0; i < N; i++)
            {
                hashy.AddItem(DataTable[i],i);
            }
            barometrePrep.instructions = hashy.RetourneBarometreInstructions();

            while(value>=0)
            {
                cout << "Enter a value to search (or negative value to quit): ";
                cin >> value;
                if(cin.good())
                {
                    if(value>=0)
                    {
                        K++;
                        search.push_back(value);
                        result.push_back(hashy.RechercheHash(value));
                        if(result.back()!=-1)
                            count++;
                        barometreRech.instructions+=hashy.RetourneBarometreInstructions();
                        cout << "Value :" << value << " is found in index : "<< result.back() << endl;
                    }
                }
                else
                {
                    cout << "Wrong input\n\r";
                }
                cin.clear();
                cin.ignore();

            }
        }    
        break;

        case TREE_SHORT: 
        case TREE_LONG:
        {
            BinaryTree bin;
            for(int i =0; i<N; i++)
            {
                bin.addnode(DataTable[i],i);
            }
            barometrePrep.instructions=bin.RetourneBarometreInstructions();
            while(value>=0)
            {
                cout << "Enter a value to search (or negative value to quit): ";
                cin >> value;
                if(cin.good())
                {
                    if(value>=0)
                    {
                        K++;
                        search.push_back(value);
                        result.push_back(bin.findNode(value));
                        if(result.back()!=-1)
                            count++;
                        barometreRech.instructions+=bin.RetourneBarometreInstructions();
                        cout << "Value :" << value << " is found in index : "<< result.back() << endl;
                    }
                }
                else
                {
                    cout << "Wrong input\n\r";
                }
                cin.clear();
                cin.ignore();
            }
        }
        break;    

        case SEQ_SHORT: 
        case SEQ_LONG:
        {
            while(value>=0)
            {
                cout << "Enter a value to search (or negative value to quit): ";
                cin >> value;
                if(cin.good())
                {
                    if(value>=0)
                    {
                        K++;
                        search.push_back(value);
                        result.push_back(RechercheSequentielle(DataTable,value,N,barometreRech));
                        if(result.back()!=-1)
                            count++;
                        cout << "Value :" << value << " is found in index : "<< result.back() << endl;
                    }
                }
                else
                {
                    cout << "Wrong input\n\r";
                }
                cin.clear();
                cin.ignore();
            }
        }
        break;

        case BIN_SHORT:
        case BIN_LONG:
        {    
            int BigDataTable[N][2];
            int i;
            for (i = 0; i < N; i++)
            {
                barometrePrep.instructions++;
                BigDataTable[i][0] = DataTable[i]; // Premiere rangee = cle
                BigDataTable[i][1] = i; // Deuxieme rangee = position dans la liste non triee
            }

            if(D==0 || (D<5 && N<2000))
            {
                methodeTri = "Tri par Insertion";
                barometrePrep.instructions+=TriParInsertion(BigDataTable,N).instructions;
            }
            else if(R<1000000)
            {
                int nbChiffre;
                nbChiffre=(int)log10(R)+1;
                methodeTri = "Tri par Base";
                barometrePrep.instructions+=TriParBase(BigDataTable,N,nbChiffre).instructions;
            }
            else
            {
                methodeTri = "Tri par Fusion";
                barometrePrep.instructions+=TriParFusion(BigDataTable, 0, N-1).instructions;
            }

            while(value>=0)
            {
                cout << "Enter a value to search (or negative value to quit): ";
                cin >> value;
                if(cin.good())
                {
                    if(value>=0)
                    {
                        K++;
                        search.push_back(value);
                        result.push_back(RechercheBinaire(BigDataTable,value,N,barometreRech));
                        if(result.back()!=-1)
                            count++;
                        cout << "Value :" << value << " is found in index : "<< result.back() << endl;
                    }
                }
                else
                {
                    cout << "Wrong input\n\r";
                }
                cin.clear();
                cin.ignore();
            }
        }
        break;
        case OPTIMIZE_SHORT:
        case OPTIMIZE_LONG:
        {
            barometrePrep.instructions = InitRechercheOptimisee(DataTable,N, R, D, &methodeTri).instructions;
            while(value>=0)
            {
                cout << "Enter a value to search (or negative value to quit): ";
                cin >> value;
                if(cin.good())
                {
                    if(value>=0)
                    {
                        K++;
                        search.push_back(value);
                        result.push_back(RechercheOptimisee(DataTable,value,N, R, D,barometreRech));
                        if(result.back()!=-1)
                            count++;
                        cout << "Value :" << value << " is found in index : "<< result.back() << endl;
                    }
                }
                else
                {
                    cout << "Wrong input\n\r";
                }
                cin.clear();
                cin.ignore();
            }
        }
        break;  
    }
    SearchTable = &search[0];
    ResultTable = &result[0];
    ShowStats();
    SaveT3(outputFile.c_str());
}