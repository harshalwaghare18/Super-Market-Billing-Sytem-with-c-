#include<iostream>
#include<fstream>

using namespace std;

class shopping
{

private :
    int pcode;
    float price;
    float dis;
    string pname;

public :
    void menu();
    void administrator();
    void buyer();
    void add();
    void edit();
    void rem();
    void list();
    void recepit();
};

void shopping :: menu()
{
    m:
    int choice;
    string email;
    string passward;

    cout<<"\n\t\t\t__________________________________________\n";
    cout<<"\t\t\t|                                        |\n";
    cout<<"\t\t\t|             SUPER MARKET MENU          |\n";
    cout<<"\t\t\t|________________________________________|\n";
    cout<<"\t\t\t|                                        |\n";
    cout<<"\t\t\t|              1)Administrator           |\n";
    cout<<"\t\t\t|________________________________________|\n";
    cout<<"\t\t\t|                                        |\n";
    cout<<"\t\t\t|              2)Buyer                   |\n";
    cout<<"\t\t\t|________________________________________|\n";
    cout<<"\t\t\t|                                        |\n";
    cout<<"\t\t\t|              3)Exit                    |\n";
    cout<<"\t\t\t|________________________________________|\n";
    cout<<"\n\t\t\t Please Enter Your Choice    : ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        cout<<"\t\t\t Please Login \t";
        cout<<"\n\t\t\t\t\t\t  Enter Email   : \t";
        cin>>email;
        cout<<"\n\t\t\t\t\t\t  Passward      : \t";
        cin>>passward;

        if(email=="admin123@gmail.com" && passward=="admin123")
        {
            administrator();
        }
        else
            {
                cout<<"Invalid User Email or passward please try again !";
            }
        break;


    case 2:
        {
            buyer();
        }

    case 3:
        {
            exit(0);
        }

    default:
        {
            cout<<"Please select the given option";
        }

}
goto m;
}

void shopping::administrator()
{
    m:
    int choice;
    cout<<"\n\t\t\t_____________________________________________\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|             Administrator Menu            |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|            1) Add The Product             |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|            2) Modify The Product          |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|            3) Delete The Product          |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|            4) Back to Main Menu           |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t                                             \n";
    cout<<"\t\t\t                                             \n";
    cout<<"\n\n\t Please Enter Your Choice     :   ";
    cin>>choice;

    switch(choice)
    {
    case 1:
        add();
        break;

    case 2:
        edit();
        break;

    case 3:
        rem();
        break;

    case 4:
        menu();
        break;

    default:
        cout<<"Invalid Choice";
    }
    goto m;
}
 void shopping:: buyer()
 {
     m:
     int choice;
     cout<<"\n\n\n\t\t\t_____________________________________________\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|                   BUYER                   |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|                1)Buy Product              |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t|                                           |\n";
    cout<<"\t\t\t|                2)Go Back                  |\n";
    cout<<"\t\t\t|___________________________________________|\n";
    cout<<"\t\t\t                                             \n";
    cout<<"\t\t\t                                             \n";
    cout<<"\n\t\t\t Please Enter Your Choice     :   ";
    cin>>choice;

     switch(choice)
     {
     case 1:
        recepit();
        break;

     case 2:
        menu();

     default:
        cout<<"Invalid Choice";
     }
     goto m;
 }

  void shopping::add()
  {
      m:
      fstream data;
      int c;
      int token=0;
      float p;
      float d;
      string n;
      cout<<"\n\t\t\t_________________________________________\n";
      cout<<"\t\t\t                                           \n";
      cout<<"\t\t\t         Add New product                   \n";
      cout<<"\t\t\t___________________________________________\n";
      cout<<"\t\t\t                                           \n";
      cout<<"\t\t\t         Product code of the product       :\t";
      cin>>pcode;
      cout<<"\t\t\t___________________________________________\n";
      cout<<"\t\t\t                                           \n";
      cout<<"\t\t\t         Name of product                   :\t";
      cin>>pname;
      cout<<"\n\t\t\t___________________________________________\n";
      cout<<"\t\t\t                                           \n";
      cout<<"\t\t\t         Price of the product              :\t";
      cin>>price;
      cout<<"\n\t\t\t___________________________________________\n";
      cout<<"\t\t\t                                           \n";
      cout<<"\t\t\t         Discount of the product           :\t";
      cin>>dis;

      data.open("database.txt", ios::in);
      if(!data)
      {
          data.open("database.txt",ios::app|ios::out);
          data<<"   "<<pcode<<"   "<<pname<<"   "<<price<<"   "<<dis<<"\n";
          data.close();
      }
      else
      {
          data>>c>>n>>p>>d;

          while(!data.eof())
          {
              if(c==pcode)
              {
                  token++;
              }
              data>>c>>n>>p>>d;
          }
          data.close();
      if(token==1)

      goto m;

      else
      {
          data.open("database.txt",ios::app|ios::out);
          data<<"   "<<pcode<<"   "<<pname<<"   "<<price<<"   "<<dis<<"\n";
          data.close();
      }
      }
      cout<<"\n\t\t\t  Record Inserted ";
  }

  void shopping::edit()
  {
      fstream data,data1;
      int pkey;
      int token=0;
      int c;
      float p;
      float d;
      string n;

      cout<<"\n\t\t\t  Modify The Record";
      cout<<"\n\t\t\t  Product Code    :   ";
      cin>>pkey;

      data.open("database.txt",ios::in);
      if(!data)
      {
          cout<<"\n\n File Doesn't Exit";
      }
      else
      {
          data1.open("database1.txt",ios::app|ios::out);

          data>>pcode>>pname>>price>>dis;

          while(!data.eof())
          {
              if(pkey==pcode)
              {

                cout<<"\n\t\t\t_____________________________________________\n";
                cout<<"\t\t\t|                                           |\n";
                cout<<"\t\t\t|              Product New Code             |\n";
                cout<<"\t\t\t|___________________________________________|\n";
                cout<<"\t\t\t|                                           |\n";
                cout<<"\t\t\t|              Name of Product              |\n";
                cout<<"\t\t\t|___________________________________________|\n";
                cin>>p;
                cout<<"\t\t\t|                                           |\n";
                cout<<"\t\t\t|              Discount                     |\n";
                cout<<"\t\t\t|___________________________________________|\n";
                cin>>d;
                cout<<"\t\t\t                                             \n";
                cout<<"\t\t\t                                             \n";
                  data1<<"   "<<c<<"   "<<p<<"   "<<d<<"\n";
                  cout<<"\n\n\t\t  Record Edited";
                  token++;
              }
          else
            {
                data1<<"   "<<pcode<<"   "<<pname<<"   "<<price<<"   "<<dis<<"\n";
            }
          data>>pcode>>pname>>price>>dis;
      }
      data.close();
      data1.close();

      remove("database.txt");
      rename("database1.txt","database.txt");

      if(token==0)
      {
          cout<<"\n\n Record not found sorry";
      }
  }
  }

  void shopping::rem()
  {
      fstream data,data1;
      int pkey;
      int token=0;
      cout<<"\n\n\t  Delete Product :";
      cout<<"\n\n\t  Product Code   :";
      cin>>pkey;
      data.open("database.txt",ios::in);
      if(!data)
      {
          cout<<" File Doesn't Exit";
      }
      else
      {
          data1.open("database1.txt",ios::app|ios::out);
          data>>pcode>>pname>>price>>dis;

          while(!data.eof())
          {
              if(pcode==pkey)
              {
                  cout<<"\n\n\t  Product is deleted successfully";
                  token++;
              }
              else
                {
                    data1<<"   "<<pcode<<"   "<<pname<<"   "<<price<<"   "<<dis<<" \n";
                }
              data>>pcode>>pname>>price>>dis;
          }
          data.close();
          data1.close();
          remove("database.txt");
          rename("database1.txt","database.txt");

          if(token==0)
          {
              cout<<"\n\n record Not Found";
          }
      }
  }

  void shopping:: list()
  {
      fstream data;
      data.open("database.txt",ios::in);
      cout<<"\n\t\t\t ________________________________________________\n";
      cout<<"\n\t\t\t\t ProNo\t\t Name \t\t Price \n";
      cout<<"\t\t\t ________________________________________________\n";

      cout<<"\t\t\t\t";
      data>>pcode>>pname>>price>>dis;

      while(!data.eof())
      {
          cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
          //data>>pcode>>pname>>price>>dis;
          cout<<"\t\t\t\t";
          data>>pcode;
          data>>pname;
          data>>price;
          data>>dis;
      }
      data.close();
  }

  void shopping:: recepit()
  {

      fstream data;
      int arrc[100];
      int arrq[100];
      char choice;
      int c=0;
      float amount=0;
      float dis=0;
      float total=0;

      cout<<"\n\n\t\t\t\t RECEPIT";
      data.open("database.txt",ios::in);
      if(!data)
      {
          cout<<"\n Empty database";
      }
      else
        {
            data.close();
      list();
      cout<<"\n\n\t\t\t _________________________________________________\n";
      cout<<"\t\t\t |                                               |\n";
      cout<<"\t\t\t |             PLEASE PLACE THE ORDER            |\n";
      cout<<"\t\t\t |_______________________________________________|\n";
      do
      {
          m:
          cout<<"\n\n\n\n\t\t\t Enter Product Code     :   ";
          cin>>arrc[c];
          cout<<"\n\t\t\t Enter the product quantity     :   ";
          cin>>arrq[c];

          for(int i=0; i<c; i++)
          {
              if(arrc[c]==arrc[i])
              {
                  cout<<"\n\n Duplicate product code. Please try again";
                  goto m;
              }
          }
          c++;
          cout<<"\n\t\t\t Do you want to buy another product if yes then press y else press any key   :   ";
          cin>>choice;
      }

      while(choice=='y');
      cout<<"\n\n\n\n\t\t\t___________________________________________RECEPIT___________________________________________";
      cout<<"\n\n\t\t\t Product NO \tProduct Name \t Product Quantity \t Price \t Amount\ Amount with discount\n";

      for(int i=0; i<c; i++)
      {
          data.open("database.txt",ios::in);
          cout<<"\t\t\t\t\t\t";
          data>>pcode>>pname>>price>>dis;

          while(!data.eof())
          {
              if(pcode==arrc[i])
              {
                  amount=price*arrq[i];
                  dis=amount-(amount*dis/100);
                  total=total+dis;
                  cout<<"\n\t\t\t "<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
              }
              cout<<"\t\t\t\t\t\t";
              data>>pcode>>pname>>price>>dis;
          }
      }
         data.close();
        }
        cout<<"\n\n\t\t\t_____________________________________________________________________________________________";
        cout<<"\n\t\t\t Total Amount   :   "<<total;
        cout<<"\n\t\t\t_______________________________________________________________________________________________";
  }

  int main ()
  {
      shopping s;
      s.menu();
  }
