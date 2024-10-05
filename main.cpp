#include "./empclass.h"
#include "./file.h"

int main()
{
    int opt;
    char ch;
    char ent;
    int key,i;
    do{
        system("clear");
        cout<<"Choose between\n1. Read Records\n2. Add record \n3. List Records\n4. Search Employee\n5. Print Payslip\n6. exit\n=>";
        cin>>opt;
        switch(opt){
        case 1:
            if(!isFileEmpty("database.txt")){
                cout<<"Reading from the file:\n";
                readFromFile(count);
                cout<<"FILE READ COMPLETE\n";
            }else{
                cout<<"FILE IS EMPTY\nPLEASE ADD SOME DATA\n";
            }
            break;
        case 2:
            system("clear");
            if(!isFileEmpty("database.txt")){
                int a=0;
                cout<<"Already data in database.\ndo you want to add new data?\ny[yes]/n[no]: ";
                cin>>ent;
                if(ent=='y'||ent=='Y'){
                    cout<<"Enter the no. of new employees: ";
                    cin>>a;
                    saveToFile(a,'a');
                }
            }else{
                cout<<"Welcome Database is empty please enter new record:\nEnter no. of employees: ";
                cin>>n;
                if(n>=SIZE){
                    cout<<"YOU CANNOT ENTER "<<n<<" EMPLOYEES AT SAME TIME. MAXLIMIT= "<<SIZE<<endl;
                    break;
                }
                saveToFile(n,'w');
            }
            break;
        case 3:
            cout<<"LISTING RECORDS:\n";
            list(count);
            break;
        case 4:
            i=0;
            cout<<"Enter the employee id you want to find: ";
            cin>>key;
            if(searchEmployee(count,key,i)==1){
                t[i].showData();
            }else if(searchEmployee(count,key,i)==0){
                cout<<"Couldn't find employee with id: "<<key<<endl;
            }else{
                cout<<"READ FROM DATABASE"<<endl;
            }
            break;
        case 5:
            cout<<"Enter the id of employee you want to print paySlip: ";
            cin>>key;
            printPayslip(count,key);
            break;
        case 6:
            cout<<"THANK YOU FOR USING OUR SOFTWARE"<<endl;
            exit(0);
            break;
        default:
            cout<<"Enter valid choices"<<endl;
        }
        cout<<"\nDo you wana continue?y[yes]/n[no]: ";
        cin>>ch;
    }while(ch=='y'||ch=='Y');
    return 0;
}