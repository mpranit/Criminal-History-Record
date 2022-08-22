#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	int choice=0;
	string password,oldpassword,pass1,pass2,pass;
	while(choice!=3)
	{
		cout<<"1.Change the password\n2.Login page to see the data\n3.Quit"<<endl;
		cout<<"Enter your choice:";
		cin>>choice;
		switch(choice)
		{
			case 1:
				{
					ifstream readin;
                    readin.open("passwordrecord.txt");   //opening the file for reading.
					cout<<"Enter your old password:";
					cin>>oldpassword;
					while(readin>>password)         //reading from file and putting in string password.
					{
						
						if(oldpassword==password)
						{
							readin.close();      //closing the file
							ofstream write;
                            write.open("passwordrecord.txt");   //opening the file for editing
							cout<<"Enter your new password:";
							cin>>pass1;
							cout<<"Confirm your new password:";
							cin>>pass2;
							if(pass1==pass2)
							{
								write<<pass1;      //changing previous written data fron newer data.
								cout<<"Congrats! password change successfully"<<endl<<endl;
							}
							write.close(); //closing the file
							
							break;
						}
						else
						{
							cout<<"Please, enter valid password."<<endl<<endl;
						}
					}
					break;
				}
			case 2:
				{
					ifstream readin;
                    readin.open("passwordrecord.txt");
					cout<<"Please enter a password:";
					cin>>pass;
					while(readin>>password)
					{
							
						if(pass==password)
						{
							cout<<"Congrats! Access granted"<<endl;
                            ofstream write;
                            write.open("criminal3.txt",ios::out|ios::app|ios::binary);  //opening another file for editing and storing the data
                             string name2;                                              
                             cout<<"\nHow many criminal record for registration:: ";
                             int num;
                             cin>>num;
                             if(num>0){
								cout<<"Write the information"<<endl;
                                for(int i=1;i<=num;i++){
                                    cin>>name2;
                                    write<<name2<<endl;
                                }
                             
                                write.close();
                             }
                             else{
                                write.close();
                             }
                             cout<<"Do you want to see the records of criminal(y/n):: ";
                             char response;
                             cin>>response;
                             cout<<endl;
                             if(response=='y'){
                                cout<<"Showing the criminals::"<<endl;
                                ifstream history;
                                history.open("criminal3.txt",ios::in|ios::binary);
                                string name;
                                while(getline(history, name)){  
                                    cout <<name<< "\n";   
                                }
								char option;
								cout<<"For exiting press y :: "<<endl;
                                cin>>option;
								if(option=='y'){
									 cout<<"Thank you";
									 break;
								}
								 
                             }
                             else{
                                cout<<"Thank you";
                             }
                            cout<<endl;
							break;
						}
						else
						{
							cout<<"Sorry! Password is wrong"<<endl;
						}
					}
					readin.close();
					break;
				}
			case 3:
				{
					break;
				}
                
			default:
				cout<<"Enter a valid choice";
		}
        cout<<endl;
	}
	return 0;
}