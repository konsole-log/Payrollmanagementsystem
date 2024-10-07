void readFromFile(int &count){
    ifstream fin;
    int id;
    char choice;
    string n,a;
    float s,all,tx,fsal;
    fin.open("database.txt");
    if(!fin){
        cerr<<"Error opening file"<<endl;
        return;
    }
    count=0;
    while(fin>>id>>n>>a>>s>>all>>tx>>fsal){
        t[count]=Employee(id,n,a,s,all,tx,fsal);
        count++;
    }
    cout<<count<<" records read from the database"<<endl;
    fin.close();
}

bool isFileEmpty(const string& filename) {
    ifstream file(filename, ios::binary | ios::ate); // Open file in binary mode and move to the end
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return true;  // Return true if file cannot be opened (could be considered "empty" in this context)
    }
    return file.tellg() == 0;  // Check if file size is 0
}

void saveToFile(int size,char mode)
{
    fstream fout;
    switch(mode){
    case 'a':
        fout.open("database.txt",ios::app);
        break;
    case 'w':
        fout.open("database.txt",ios::out);
        break;
    }
    if(fout.fail()){
        cout<<"file was not created"<<endl;
        return;
    }
    for(int i=0;i<size;i++){
        e[i].getData();
        e[i].calFinalSalary();
        fout<<e[i].empid<<" "<<e[i].name<<" "<<e[i].address<<" "<<e[i].bsalary<<" "<<e[i].allowance<<" "<<e[i].tax<<" "<<e[i].fsalary<<endl;
    }
    cout<<size<<" entries added"<<endl;
    if(mode=='a'){
        readFromFile(count);
    }
    fout.close();
}

void list(int size){
    if(size==0){
        cout<<"ERROR!!seems like you are trying to list without reading from database.";
        return;
    }
    cout<<"\t\t\t\t\t\t\tEMPLOYEE DETAILS"<<endl;
    cout<<"\t\t+";
    for(int j=0;j<95;j++)cout<<"-";
    cout<<"+"<<endl;
    cout<<left;
    cout<<"\t\t| "<<setw(col1)<<"Employee ID"<<" |";
    cout<<setw(col2)<<"Name"<<" |";
    cout<<setw(col3)<<"Address"<<" |";
    cout<<setw(col4)<<"Salary"<<" |";
    cout<<setw(col5)<<"Allowance"<<" |";
    cout<<setw(col6)<<"Tax"<<" |";
    cout<<setw(col7)<<"Net Salary"<<" |";
    cout<<endl;
    cout<<"\t\t+";
    for(int j=0;j<95;j++)cout<<"-";
    cout<<"+"<<endl;
    for(int i=0;i<size;i++){
        t[i].showData();
    }
    cout<<"\t\t+";
    for(int j=0;j<95;j++)cout<<"-";
    cout<<"+"<<endl;
}
int searchEmployee(int &count,int key,int &index){
    if(count==0){
        return -1;
    }
    for(index=0;index<count;index++){
        if(t[index].empid==key){
            return 1;
            break;
        }
    }
    return 0;
}
void printPayslip(int &count,int id){
    int i=0;
    fstream fout;
    fout.open("paid.txt",ios::app);
    if(searchEmployee(count, id, i)==-1){
        cout<<"PLEASE READ FROM THE FILE FIRST"<<endl;
    }else if(searchEmployee(count,id,i)==0){
        cout<<"COULDN'T FIND EMPLOYEE ID: "<<id;
    }else{
        ifstream fin;
        fin.open("paid.txt");
        string n,a;
        int paid;
        int found=0;
        float s,all,tx,fsal;
        while(fin>>paid>>n>>a>>s>>all>>tx>>fsal){
            if(paid==t[i].empid){
                found = 1;
                break;
            }
        }
        fin.close();
        int width=60;
        if(found==0){
            fstream fout;
            fout.open("paid.txt",ios::app);
            cout<<endl<<endl;
            cout<<"\t\t\t+-----------------------------------PAYSLIP---------------------------------+\t\t\t\t\t\t\t\t"<<endl;
            cout<<"\t\t\t| Emloyee ID:"<<t[i].empid<<setw(25)<<"Name:"<<t[i].name
            <<setw(20)<<"Address:"<<t[i].address<<setw(2)<<"|"<<endl;
            cout<<"\t\t\t|---------------------------------------------------------------------------|"<<endl;
            cout<<"\t\t\t| Salary:"<<t[i].bsalary<<setw(63)<<" |"<<endl;
            cout<<"\t\t\t| Allowance:"<<t[i].allowance<<setw(61)<<" |"<<endl;
            cout<<"\t\t\t| Tax:"<<t[i].tax<<setw(67)<<" |"<<endl;
            cout<<"\t\t\t| ------------------                                                        |"<<endl;
            cout<<"\t\t\t| Net Salary:"<<t[i].fsalary<<setw(59)<<" |"<<endl;
            cout<<"\t\t\t+---------------------------------------------------------------------------+\t\t\t\t\t\t\t\t"<<endl;
            fout<<t[i].empid<<" "<<t[i].name<<" "<<t[i].address<<" "<<t[i].bsalary<<" "<<t[i].allowance<<" "<<t[i].tax<<" "<<t[i].fsalary<<endl;
        }else{
            cout<<"Employee id with "<<paid<<" has already taken salary"<<endl;
        }
    }
}