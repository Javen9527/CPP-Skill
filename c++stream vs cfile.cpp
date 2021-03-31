//======================= c file =======================
 FILE *f = fopen(path, "r");
    if(f != NULL)
    {
        char c = fgetc(f);
        
        while(c != EOF)
        {
            if(c == '#')
            {
            }
            else if(c != '\n')
            {
                ungetc(c, f);
                fscanf(f, "%lf %lf", &x, &y);
                cout << "x = "<< x << " "<< "y = " << y << endl;
            }
            c = fgetc(f);
        }
    }
    fclose(f);

//======================= c++ stream =======================
fstream f(path);
    std::filebuf* p = f.rdbuf();
    
    char c = p->sbumpc();
    while(c != EOF)
    {
        if(c == '#')
        {
        }
        else if(c != '\n')
        {
            p->sungetc();
            f >> x >> y;
            cout << "x = "<< x << " "<< "y = " << y << endl;
        }
        c = p->sbumpc();
    }
