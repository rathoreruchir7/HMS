#include <bits/stdc++.h>
#include<string>
#include<cstring>
using namespace std;
#include<istream>
#include <fstream>

////////////////
class Room
{
   int roomNumber;
   string status;
   int patientId;

   void getRoom()
   {
      cout<<"enter the room number and the patient id and the status....\n";
      cin>>roomNumber>>patientId>>status;
   }

   public:
   void showRoom()
   {
      cout<<"room number->"<<roomNumber<<"  status ->"<<status<<"  patient id->"<<patientId;
   }
  friend void addRoom(Room &);
  friend void removeRoom(Room &);
};

void addRoom(Room &rm)
{
   rm.getRoom();
}


void removeRoom(Room &rm)
{
  rm.status="vacant";
  rm.patientId=0;
}

int rm_n=0;

/////////////
/////////////////////////////

class hospital{
   string branch;
   string address;
   string city;
   int hosp_id,hosp_pwd;
   


   
    void getHospital()
    { cout<<"enter the hospital id and password.."<<endl;
       cin>>hosp_id>>hosp_pwd;
       cout<<"enter the branch , address and city."<<endl;
      cin>>branch>>address>>city;
    }

    public:
      Room rm[100];
    void showHospital()
    {
      cout<<branch<<endl<<address<<endl<<city<<endl;
    }

    friend int checkHospital(hospital &,int,int);
    friend void addHospital(hospital &);
};
hospital hosp[10];
int h_n=0;
void addHospital(hospital &hosp)
{
  hosp.getHospital();
   ofstream file_obj; 

  // Opening file in append mode 
  file_obj.open("Inputhospital.dat", ios::app);
  file_obj.write((char*)&hosp, sizeof(hosp)); 
  file_obj.close();
}

void readhospital()
{
  fstream file_obj; 

  // Opening file in input mode 
  file_obj.open("Inputhospital.dat", ios::in|ios::out|ios::ate|ios::binary);
  hospital a;
  file_obj.clear();
  file_obj.seekg(0);
  file_obj.read((char*)&a, sizeof(a));
 // ad_n++;
  while (!file_obj.eof()) { 
    // Assigning max ratings 
    
    // Checking further
     h_n++;
     hosp[h_n]=a;hosp[h_n].showHospital();
     file_obj.read((char*)&a, sizeof(a));
    
  
  } 
 
 }
int checkHospital(hospital &hosp,int ID,int PWD)
{
  if(ID=hosp.hosp_id && PWD==hosp.hosp_pwd)
    return 1;
  else 
    return 0;
}

class admin{
  private:
   int id,admin_pwd;
   char admin_name[30];
  
      
    void getAdmin(){
      cout<<"enter id, password and Name of new admin.."<<endl;
      
      cin >> id >> admin_pwd>>admin_name;
     
      cout<<"Admin registered  id="<<id<<" Admin Name --> "<<admin_name<<endl;

     


    }

    friend void removeAdmin(admin &);
    friend int checkAdmin(admin &,int);
    friend void addAdmin(admin &);
  public:
    void showAdmin()
    {
      cout<<" "<<id<<" "<<admin_name<<endl;
    }

  
};
void removeAdmin(admin &ad)
{
  //ad.admin_name="";
  ad.id=0;
  ad.admin_pwd=0;
}

int  checkAdmin(admin &ad,int ID)
{
  if(ad.id==ID)
    return 1;
  else
    return 0;
}
int ad_n=1;
admin ad[10];
void addAdmin(admin &ad)
{
  ad.getAdmin();
   ofstream file_obj; 

  // Opening file in append mode 
  file_obj.open("Inputadmin.dat", ios::app);
  file_obj.write((char*)&ad, sizeof(ad)); 
  file_obj.close();

}
void readAdmin()
{
  fstream file_obj; 

  // Opening file in input mode 
  file_obj.open("Inputadmin.dat", ios::in|ios::out|ios::ate|ios::binary);
  admin a;
  file_obj.clear();
  file_obj.seekg(0);
  file_obj.read((char*)&a, sizeof(a));
 // ad_n++;
  while (!file_obj.eof()) { 
    // Assigning max ratings 
    
    // Checking further 
     ad[ad_n]=a;ad[ad_n].showAdmin();ad_n++;
    file_obj.read((char*)&a, sizeof(a));
  
  } 
 
 }
  



//////////////////////////////////////
class prescribedTests
{
  int patientId,testId;
  string status,name;
  float cost;

 
  void getPrescribedTest()
  {
     cout<<"enter the patient id , testid, name,cost and status"<<endl;
     cin>>patientId>>testId>>name>>cost>>status;
    }
 public:
    void showPrescribedTest()
  {
    cout<<"patientId-->"<<patientId<<"   Test ID-->"<<testId<<"   test name-->"<<name<<"   Cost-->"<<cost<<"   status-->"<<status<<endl;

  }
    friend void performTest();
    friend void performTest1(prescribedTests &);
    friend int checkTestStatus(prescribedTests &);
    friend void addPrescribedTest(prescribedTests &);
};

////////////////////////////////////
class doctor;
class Department
{

 int dept_id;
 int dept_pwd;
 string dept_name;
 int doctor_n;
 doctor *da;

void getDepartment()
  {
    cout<<"enter the number of doctors to add in department.."<<doctor_n;

  }
public:
  void showDepartment()
  {
    cout<<"department ID-->"<<dept_id<<"  Department Name-->"<<dept_name<<"Number of doctors-->"<<doctor_n<<endl;
  }
 // void setDoctor(doctor &d)
 // {
 //   da=d;
 // }
};

// };
///////////////////////
class prescribedMedicines;
class patient;
 
class medicine;
class test;
class Bill
{
  int patient_Id,bill_t=0,bill_med=0;
  float bill_cost=0;
  string status;
    
    int bill_medicines[50],bill_tests[50];

    void getBill()
    {
        cout<<"enter the id of the new patient..."<<endl;
        cin>>patient_Id;
        
    }
   public:
    void showBill()
    {
      cout<<"Patient ID -->"<<patient_Id<<endl;

      for(int i=1;i<=bill_t;i++)
      {  cout<<i<<" ";                                    //likely to be changed the range of i
        cout<<"tests ID-->"<<bill_tests[i]<<"  ";
          cout<<endl;
      }

      for(int i=1;i<=bill_med;i++)
      {
        cout<<i<<" ";
        cout<<"Medicine ID-->"<<bill_medicines[i]<<"  ";
        cout<<endl;
    }

    cout<<"Total Bill Cost = "<<bill_cost<<endl;
    
  
 }

 friend void updateBillByPharmacist(Bill &,medicine &);
 friend void updateBillByLabAssisstant(Bill &,test &);
 friend int checkBill(Bill &,int);
 friend void addBill(Bill &);
 friend void payBill(Bill &);
};


int bill_n=0;
Bill bi[50];

void addBill(Bill &bi)
{
  bi.getBill();
}
class medicine{
   
     int medId;
   string medName;
   float cost;

void getMedicine()
{
  cout<<"entr the medicine id ,medicine name and the cost of the medicine"<<endl;
  cin>>medId>>medName>>cost;

}

public:
void showMedicine()
{
  cout<<"Medicine Id-->"<<medId<<"  Medicine Name-->"<<medName<<"  medicine cost-->"<<cost<<endl;
}
 
 friend void func_prescribedMedicine(prescribedMedicines &,medicine &);  
 friend int  checkMedicine(medicine &,int);
 friend void updateBillByPharmacist(Bill &,medicine &);
 friend void sellMedicine(medicine &,patient &);
 friend void addMedicine(medicine &);
};
medicine med[50];
int med_n=0;
///////////////////////////////////

class prescribedMedicines
{
   int medicineId,patientId;
   string medicineName,status;

   void getPrescribedMedicine()
   {
     cout<<"enter the medicine ID,patient ID, and the medicine name and status..."<<endl;
     cin>>medicineId>>patientId;
     cin>>medicineName;
     cin>>status;
   }

 public:
  void showPrescribedMedicine()
  {
    cout<<"Medicine ID-->"<<medicineId<<"   Medicine Name-->"<<medicineName<<"    Patient ID-->"<<patientId<<"   status-->"<<status<<endl;
  }
   friend void addPrescribedMedicine(prescribedMedicines &);
   friend void func_prescribedMedicine(prescribedMedicines &,medicine &); 
   friend int checkPrescribedMedicine(prescribedMedicines &);
   friend void performPrescribedMedicine(prescribedMedicines &);
};
prescribedMedicines pm[50];
int pm_n=0;
///////////////////////////////

class patient{
  
  int patientId,age,phoneNumber,patientPass;
  string patientName,address,disease;

  int tests[30],medicines[30];                  //assuming medicine is the only treatment.
  int t=0,med=0;


  
  void getPatient()
  {
     cout<<"enter patient Name-->"; cin>>patientName;
     cout<<"enter password-->"<<patientPass;
     cout<<"Age-->";cin>>age;
     cout<<"Phone number-->";cin>>phoneNumber;
     cout<<"Address-->";cin>>address;
     cout<<"Patinet ID-->";cin>>patientId;
     cout<<"Disease-->";cin>>disease;


  }
 public:
  void showPatient(){
   cout<<"Patient Name-->"<<patientName<<"\nAge-->"<<age<<"\nPhone Number-->"<<phoneNumber<<"\nAddress-->"<<address<<"\nPatient ID-->"<<patientId<<"\ndisease-->"<<disease<<endl<<endl;
  }

friend void addPatient(patient &);
friend int checkPatient(patient &,int);
friend void removePatient(patient &);
friend void showPatientRecord(patient &);
friend void sellMedicine(medicine &,patient &);
friend void doTest(patient &,test &);

};

patient pat[20];
int pat_n=0;

////////////////////////////////


////////////////////////////////////////

void payBill(Bill &b)
{
  b.status="paid";
  cout<<"Bill paid"<<endl;
}


void addMedicine(medicine &med)
{
  med.getMedicine();
}
 
int checkMedicine(medicine &med,int medID)
{
  if(medID==med.medId)
    return 1;

  else 
    return 0;
}


class test
{
   private:
      int testId;
      string name;
      float cost;
    
      void getTest();
    public:
      void showTest()
      {
        cout<<"test id -->"<<testId<<"   "<<"test name -->"<<name<<"   "<<"test cost -->"<<cost<<endl;
      }
 friend void performTest(prescribedTests &,test &);
 friend void performTest1(prescribedTests &);
 friend class labAssisstant;
 friend void addTest(test &);
 friend void updateBillByLabAssisstant(Bill &,test &);
 friend int checkTest(test &,int );
 friend void doTest(patient &,test &);
};

test t[30];
int t_n=0;
void test::getTest()
      {
        cout<<" enter the test id,test nsme, and test cost...."<<endl;
        cin>>testId>>name>>cost;
        t_n++;
      }



int checkTest(test &t,int test_id)
{
  if(test_id==t.testId)
    return 1;
  else
    return 0;
}
//////////////////////
void addPrescribedTest(prescribedTests &pt)
{
  pt.getPrescribedTest();
}


int checkPrescribedMedicine(prescribedMedicines &pm)
{
  if(pm.status=="pending")
    return 1;

  else
    return 0;
}


void performPrescribedMedicine(prescribedMedicines &pm)
{
  pm.showPrescribedMedicine();
  pm.status="sold";
  pm.showPrescribedMedicine();

}
void addPrescribedMedicine(prescribedMedicines &pm)
{
  pm.getPrescribedMedicine();
}

void func_prescribedMedicine(prescribedMedicines &pm,medicine &med)             //for doctor purpose
{
    // cout<<"enter the name of the medicine"<<endl;
    // string name1;
    // getline(cin,name1);

    //  int i,check=0;

    //  for(i=0;i<=med_n;i++)
    //  {
    //   if(med[i].medName==name1)
    //   {  check=1;
    //     showMedicine(med[i]);
    //     cout<<endl;
    //     pm_n++;
    //     pm[pm_n].getPrescribedMedicine();
    //   }
    //  }
    //  if(check==0)
    //   cout<<"medicine not present..."<<endl;
}
void sellMedicine(medicine &med,patient &pat)                               //for the pharmacist
       {
           pat.med++;
           pat.medicines[pat.med]=med.medId;

       }             

      


prescribedTests pt[30]; 
int pt_n;

void performTest(prescribedTests &pt,test &t)
{
  // string testname;
 //  cout<<"enter the test name";
  // cin>>testname;
  // int check=0;

  // for(int i=0;i<=t_n;i++)
  // {
  //  if(t[i].name==testname)
  //    {
  //      check=1;
 //                t[i].showTest();
      
  //    }
  // }

  // if(check==1)
  // {
  //  pt_n++;
  //  pt[pt_n].getPrescribedTest();                       //only for doctor
   
  // }
  // if(check==0)
  // {
  //  cout<<"no test found..."<<endl;
  // }

}

void performTest1(prescribedTests &pt)
{
    pt.status="completed";
    cout<<"the test has been performed..."<<endl;
    pt.showPrescribedTest();
}

class staff
{ protected:
   int st_id,st_pwd;
   char st_name[30];
  
  // private:
  //   void getStaff()
  //   {
  //     cout<<"enter the id and password of new staff"<<endl;
  //     cin>>st_id>>st_pwd;
    
   // public:
   // void addstaff();
  
   // friend class labAssisstant;
};
class doctor: public staff
{
    string dept;

  
    void prescribeTest();
  void prescribeMedicines();
  void PatientReprt();
  
  
    void getDoctor();

public:
  void showDoctor()
  {
    cout<<"the doctor id ->"<<st_id<<"  Name->"<<st_name<<endl;   //add name in place of password
  }
    
  friend void addstaff(doctor &);
    friend int checkDoctor(doctor &,int ,int);
    friend void addDoctor(doctor &);
    friend void removeDoctor(doctor &);
};

doctor doc[20];
int doc_n=0;



staff st[50];
int st_n=0;

void doctor:: getDoctor()
    {
        
       
          cout<<"enter the new id and password"<<endl;
          cin>>st_id>>st_pwd;  
          cout<<"enter teh name of the doctor";
          cin>>st_name;  }
  
    

void addstaff(doctor &doc)
   {
       int choice;
       cout<<"1. add doctor\n2. add lab assisstant\n3. add pharmacist\n4. add receptionist."<<endl;
       cin>>choice;
       if(choice==1)
       {  
          
          doc_n++;

          doc.getDoctor();

       }
   }
class labAssisstant : public staff
{
  void getlabAssisstant()
  {
    cout<<"enter the new id of lab assisstant and password and name\n"<<endl;
    cin>>st_id>>st_pwd;
    cin>>st_name;
  }
  public:
  void addTest(test &);
  void showlabAssisstant()
  {
    cout<<"the lab assisstant id is ->"<<st_id<<"   Name ->"<<st_name<<endl;
  }
  
  friend int checklabAssisstant(labAssisstant &,int ,int);
  friend void addlabAssisstant(labAssisstant &);
  friend void removelabAssisstant(labAssisstant &);
};

void addTest(test &t)
{
  t.getTest();

}


labAssisstant la[20];
int la_n=0;

void labAssisstant::addTest(test &t)
  {  int id,pwd;
       cout<<"enter the lab assisstant id and password"<<endl;
       cin>>id>>pwd;

       for(int i=0;i<la_n;i++)
       {
          if(id==la[i].st_id && pwd==la[i].st_pwd)
          {
            
            t.getTest();
          }
       }
  }


  class receptionist:public staff{
   
   void getReceptionist()
   {
      cout<<"enter the new id and the password of the receptionist and the name"<<endl;
      cin>>st_id>>st_pwd;
      cin>>st_name;
   }
   public:
   void showReceptionist()
   {
      cout<<"the receptionist id is ->"<<st_id<<"  Name ->"<<st_name<<endl;
   }
 
 friend void addReceptionist(receptionist &);
 friend int checkReceptionist(receptionist &,int ,int);
 friend void removeReceptionist(receptionist &);
  };

receptionist rec[20];
int rec_n=0;


void addPatient(patient &pat)
{
  pat.getPatient();

}

int checkPatient(patient &pat,int id)
{
     if(id==pat.patientId)
     {
      return 1;
     }
     else
      return 0;
}

void showPatientRecord(patient &pat)
{
 pat.showPatient();
                                                               // int tests[30],medicines[30];                  //assuming medicine is the only treatment.
                                                               //  int t=0,med=0;
  cout<<" All Tests ID--> ";
  for(int i=1;i<=pat.t;i++)
    cout<<pat.tests[i]<<" ";

  cout<<"\nAll medicines ID--> ";

   for(int i=1;i<=pat.med;i++)
   {
     cout<<pat.medicines[i]<<" ";
   }
   cout<<endl;
}


void removePatient(patient &pat)
{
  pat.patientId=0;
  pat.patientName="";
  pat.phoneNumber=0;
  pat.address="";
  pat.disease="";
  pat.age=0;
}

void addPrescriptionToPatient(patient &pat)
{

}
// class medicines
// {
//    string name;
//    int medicine_Id;
//    float cost;  

// public:
//  void showMedicines()
//  {
//    cout<<"medicine id -->"<<medicine_Id<<"   "<<"medicine name -->"<<name<<"   "<<"medicine cost -->"<<cost<<endl;
//  }

//  };

// class prescribedMedicine()
// {
  
// }

void doTest(patient &pat,test &te)
{
   pat.t++;
   pat.tests[pat.t]=te.testId;
}
int checkReceptionist(receptionist &rec,int id, int pwd)
{
  if(id==rec.st_id && pwd==rec.st_pwd)
  {
    return 1;
  }
  else 
    return 0;

}

void addReceptionist(receptionist &rec)
{
  rec.getReceptionist();
}

void removeReceptionist(receptionist &rec)
{
   rec.st_id=0;
   rec.st_pwd=0;
}
int checkDoctor(doctor &doc,int id,int pwd)
{
   if(id==doc.st_id && pwd==doc.st_pwd)
    return 1;
   else
    return 0;
}

int checklabAssisstant(labAssisstant &la,int pid,int ppwd)
{
  if(pid==la.st_id && ppwd==la.st_pwd)
    return 1;
   else
    return 0;

}
int checkTestStatus(prescribedTests &pt)
{
  if(pt.status=="pending")
    return 1;
  else
    return 0;
}
void addDoctor(doctor &doc)
{
    doc.getDoctor();
    ofstream file_obj; 

  // Opening file in append mode 
  file_obj.open("Inputdoctor.dat", ios::app);
  file_obj.write((char*)&doc, sizeof(doc)); 
  file_obj.close();
}

void readdoctor()
{
  fstream file_obj; 

  // Opening file in input mode 
  file_obj.open("Inputdoctor.dat", ios::in|ios::out|ios::ate|ios::binary);
  doctor a;
  file_obj.clear();
  file_obj.seekg(0);
  file_obj.read((char*)&a, sizeof(a));
 // ad_n++;
  while (!file_obj.eof()) { 
    // Assigning max ratings 
    
    // Checking further
     doc_n++;
     doc[doc_n]=a;
     file_obj.read((char*)&a, sizeof(a));
    
  
  } 
 
 }
  

void addlabAssisstant(labAssisstant &la)
{
  la.getlabAssisstant();
   ofstream file_obj; 

  // Opening file in append mode 
  file_obj.open("Inputlabassistant.dat", ios::app);
  file_obj.write((char*)&la, sizeof(la)); 
  file_obj.close();
}

void readla()
{
  fstream file_obj; 

  // Opening file in input mode 
  file_obj.open("Inputlabassistant.dat", ios::in|ios::out|ios::ate|ios::binary);
  labAssisstant a;
  file_obj.clear();
  file_obj.seekg(0);
  file_obj.read((char*)&a, sizeof(a));
 // ad_n++;
  while (!file_obj.eof()) { 
    // Assigning max ratings 
    
    // Checking further
     la_n++;
     la[la_n]=a;
     file_obj.read((char*)&a, sizeof(a));
    
  
  } 
 
 }


void removeDoctor(doctor &doc)
{
   doc.st_pwd=0;
   doc.st_id=0;
   cout<<"doctor removed....";
}

void removelabAssisstant(labAssisstant &la)
{
  la.st_pwd=0;
  la.st_id=0;
  cout<<"lab asisstant removed....";
}


//////////////////////////////////////

int checkBill(Bill &bi,int patientID)
{
  if(patientID==bi.patient_Id)
  {
    return 1;
  }
  else
    return 0;
}
void updateBillByPharmacist(Bill &bi,medicine &med)
{
   
   bi.bill_med++;
   bi.bill_medicines[bi.bill_med]=med.medId;
   bi.bill_cost+=med.cost;
   
   
}

//////////////////////////////////////////////////////////


class pharmacist: public staff
{
  void getPharmacist()
  {
    cout<<"enter the new id and password of the pharmacist and the name"<<endl;
    cin>>st_id>>st_pwd;
    cin>>st_name;
  }

public:
  void showPharmacist()
  {
    cout<<"Pharmacist id -->"<<st_id<<"  Name -->"<<st_name<<endl;
  }
  friend int checkPharmacist(pharmacist &,int,int);
  friend void removePharmacist(pharmacist &);
  friend void addPharmacist(pharmacist &phar);
};
 pharmacist phar[20];
 int phar_n=0;

void addPharmacist(pharmacist &phar)
{
  phar.getPharmacist();
}


void removePharmacist(pharmacist &phar)
{
  phar.st_id=0;
  phar.st_pwd=0;
}

int checkPharmacist(pharmacist &phar,int phar_id,int phar_pwd)
{
  if(phar.st_id==phar_id && phar.st_pwd==phar_pwd)
    return 1;
  else
    return 0;
}





void updateBillByLabAssisstant(Bill &bi,test &t)
{
  bi.bill_t++;
  bi.bill_tests[bi.bill_t]=t.testId;
  bi.bill_cost+=t.cost;
}

//////////////////////////////////////

int main()

{  
  cout<<"-----ALL ADMINS------"<<endl;
 readAdmin();
 cout<<" "<<40<<" Ruchir"<<endl;
  readdoctor();
  readla();

  
  
  
  int id,ad_pwd;
   cout<<"*********************Administrator Login***************************"<<endl;
   cout<<"admin ID";
   cin>>id;
   cout<<"admin password";
   cin>>ad_pwd;

   if(id==40 && ad_pwd==007)
   {
      int ch1;


      while(1)
      {  cout<<"\n1. add admin"<<endl<<"2. show admin"<<endl<<"3. hospital login "<<endl<<"4. add hospital"<<endl<<"5. exit\n";

        cout<<"enter  your choice.."<<endl;
        cin>>ch1;
         switch(ch1)
         {
          case 1:
                ad_n++;
              addAdmin(ad[ad_n]);
              break;

          // case 2:
          //       cout<<"enter the id of the admin to remove.."<<endl;
          //       int id;
          //       cin>>id;
          //        int check22;
          //       for(int i=1;i<=ad_n;i++)
          //       {
          //         check22=checkAdmin(ad[i],id);
          //         if(check22==1)
          //         {
          //           removeAdmin(ad[i]);
          //           ad_n--;
          //           break;
          //         }
          //       }
          //       if(check22==0)
          //         cout<<"invalid admin ID.."<<endl;

          //       break;

            case 2:
              for(int i=1;i<ad_n;i++)    //show all admin
                {   cout<<i<<" ";
                  ad[i].showAdmin();
                }
                break;
            
            case 4:
              h_n++;
              addHospital(hosp[h_n++]);
              break;
            case 3:
              int h_id,h_pwd;
              cout<<"enter hospital id and password"<<endl;
              cin>>h_id>>h_pwd;
              int check21;
              check21=0;

              for(int z=1;z<=h_n;z++)
              {
                check21=checkHospital(hosp[z],h_id,h_pwd);
                if(check21==1)
                  {
                int ch;
                while(1)
                 {
              cout<<"\n1. doctor login\n2. lab assisstant login \n3. add staff\n4. show staff \n5. remove staff\n6. receptionist login\n7.Pharmacist login\n8.Patient login\n9.exit hospital class"<<endl;
             cin>>ch;
             if(ch<=8){
            switch(ch)
          {
           case 1:
          int id,pwd,i;
          cout<<"enter the doctor ID and Login"<<endl;
          cin>>id>>pwd;
          int check;
          check=0;

          for(i=1;i<=doc_n;i++)
          {  check=checkDoctor(doc[i],id,pwd);
             if(check==1)
             {
            cout<<"1. prescribe Test\n2.prescribeMedicines\n"<<endl;
                    int c1;
                    cout<<"enter your choice, Doctor!!.."<<endl;
                    cin>>c1;

                    if(c1==1)
                    {
                      cout<<"enter the ID of the test to add to the prescription..>>";
                      int test_id;
                      cin>>test_id;
                      int check1=0;
                      for(int j=1;j<=t_n;j++)
                      {
                        check1=checkTest(t[j], test_id);
                        if(check1==1)
                        {
                           pt_n++;
                      addPrescribedTest(pt[pt_n]);
                      break;
                        }
                      }
                      if(check1==0)
                        cout<<"the required test is not available in the hospital..."<<endl;

                  }

                    if(c1==2)
                    {
                       cout<<"enter the medicine ID to add to the prescription..."<<endl;
                       int med_id;
                       cin>>med_id;
                       int check1=0;

                       for(int j=1;j<=med_n;j++)
                       {
                        check1=checkMedicine(med[j],med_id);
                        if(check1==1)
                        {  med[j].showMedicine();
                            pm_n++ ;                                                 // prescribedMedicine
                       addPrescribedMedicine(pm[pm_n]);
                       break;
                        }
                       }
                       if(check1==0)
                        cout<<"the required medicine is not available in the hospital....>>";

                      
                    }
                    break;
          }
        }

            if(check==0)
           {  cout<<"invalid credentials..."<<endl;}
            

            break;

            case 2:
             int pid,ppwd;
             cout<<"enter the lab asisstant id and login...>>>"<<endl;
             cin>>pid>>ppwd;

             for(i=1;i<=la_n;i++)
             { int check1=checklabAssisstant(la[i],pid,ppwd);
              if(check1==1)
              {
                   cout<<"1. perform the tests\n2. add new tests\nenter the choice >>>>"<<endl;
                   int c2;
                   cin>>c2;

                   if(c2==1)
                   {
                   for(i=1;i<=pt_n;i++)
                   { int check2=checkTestStatus(pt[i]);
                    if(check2==1)
                    { int patient_id,test_id;
                      performTest1(pt[i]);
                      cout<<"\nEnter the patient id and test id to update the patient report...>>";
                      cin>>patient_id>>test_id;
                      
                      
                      for(i=0;i<=pat_n;i++)
                      {
                        int check3=checkPatient(pat[i],patient_id);
                        if(check3==1)
                        {
                          break;
                        }
                      }
                      int j;
                      for( j=1;j<=t_n;j++)
                      {
                        int check3=checkTest(t[j],test_id);
                        if(check3==1)
                        {
                          break;
                        }

                        
                      }
                      doTest(pat[i],t[j]);

                      for(int i=1;i<=bill_n;i++)
                      {
                        int check3=checkBill(bi[i],patient_id);

                        if(check3==1)
                        {
                           break;
                        }
                      }
                      updateBillByLabAssisstant(bi[i],t[j]);

                    }
                   }
                   cout<<"all tests updated...";
                   }
                   
          
                    if(c2==2)
                       { t_n++;
                         addTest(t[t_n]);
                             }
             }
            }
            if(i==la_n)
              cout<<"invalid credentials...."<<endl;

              break;

            case 3:
               cout<<"1. doctor\n2.lab assisstant\n3. receptionist\n4. pharmacist\n enter  your choice...."<<endl;
               int ch1;
               cin>>ch1;

               if(ch1==1)
               {
                  doc_n++;
                  addDoctor(doc[doc_n]);
               }

               if(ch1==2)
               {
                la_n++;
                addlabAssisstant(la[la_n]);
               }

               if(ch1==3)
               {
                   rec_n++;
                   addReceptionist(rec[rec_n]);
               }
               if(ch1==4)
               {
                phar_n++;
                addPharmacist(phar[phar_n]);

               }

               break;
            case 4:
               cout<<"1. doctor\n2. lab assisstant\n3. receptionist\n4. pharmacist\nenter your choice..."<<endl;
               int ch2;
               cin>>ch2;

               if(ch2==1)
               {
                  for(i=1;i<=doc_n;i++)
                  {
                     doc[i].showDoctor();
                  }
               }

               if(ch2==2)
               {
                for(i=1;i<=la_n;i++)
                {
                  la[i].showlabAssisstant();
                }
               }

               if(ch2==3)
               {
                for(i=1;i<=rec_n;i++)
                {
                  rec[i].showReceptionist();
                }
               }

               if(ch2==4)
               {
                for(i=1;i<=phar_n;i++)
                {
                  phar[i].showPharmacist();
                }
               }

               break;

               case 5:
                 cout<<"1. doctor\n2.lab assisstant\n3. receptionist\n4. pharmacist\nenter your choice..."<<endl;
                 int ch3;
                 cin>>ch3;

                 if(ch3==1)
                 {  int did,dpwd;
                  cout<<"enter the id and password of the doctor to remove...\n"<<endl;
                  cin>>did>>dpwd;

                  for(i=1;i<=doc_n;i++)
                  {
                    int check3=checkDoctor(doc[i],did,dpwd);

                    if(check3==1)
                    {
                      removeDoctor(doc[i]);
                    }
                  }
                 }

                 if(ch3==2)
                 {   int laid,lapwd;
                  cout<<"enter the id and password of the lab assisstant to remove...\n"<<endl;
                  cin>>laid>>lapwd;
                    
                    for(i=1;i<=la_n;i++)
                    {
                      int check4=checklabAssisstant(la[i],laid,lapwd);

                      if(check4==1)
                      {
                        removelabAssisstant(la[i]);
                      }
                    }

                 }

                 if(ch3==3)
                 {
                   int recid,recpwd;
                   cout<<"enter the receptionist id and passwoprd to remove...\n"<<endl;

                   cin>>recid>>recpwd;

                   for(i=1;i<=rec_n;i++)
                   {
                     int check5=checkReceptionist(rec[i],recid,recpwd);

                     if(check5==1)
                     {
                       removeReceptionist(rec[i]);
                     }
                   }
                 }
                  if(ch3==4)
                    {
                      int phar_id,phar_pwd;
                      cout<<"enter the id and the password of the pharmacist to remove..."<<endl;
                      cin>>phar_id>>phar_pwd;

                      for(i=1;i<=phar_n;i++)
                      {
                        int check8=checkPharmacist(phar[i],phar_id,phar_pwd);

                        if(check8==1)
                        {
                          removePharmacist(phar[i]);
                        }
                      }
                    }

                 break;

                 case 6:
                    int rec_id,rec_pwd;
                    cout<<"enter the id and password of the receptionist\n";
                    cin>>rec_id>>rec_pwd;

                   for(i=1;i<=rec_n;i++)
                   {
                     int check6=checkReceptionist(rec[i],rec_id,rec_pwd);

                     if(check6==1)
                     {
                       cout<<"1. allocate rooms,add patient\n2. disallocate rooms and remove patient\n3. show patient report\n4.show bill \n enter your choice... ";
                            
                        int ch4;
                        cin>>ch4;

                        if(ch4==1)
                        {
                          pat_n++;
                         addPatient(pat[pat_n]);
                         rm_n++;

                           rm_n++;
                           addRoom(hosp[z].rm[rm_n]);

                           bill_n++;
                           addBill(bi[bill_n]);
                        }

                     
                   

                     if(ch4==2)
                     {
                        cout<<"enter the room number to disallocate.."<<endl;
                        int rm_num;
                        cin>>rm_num;

                        removeRoom(hosp[z].rm[rm_num]);                                 //assuming that the rooms are not protected.

                        cout<<"enter the patient id to remove"<<endl;
                        int pat_id;
                        cin>>pat_id;

                        for(i=1;i<=pat_n;i++)
                        {
                          int check7=checkPatient(pat[i],pat_id);
                          if(check7==1)
                            {
                              removePatient(pat[i]);
                            }
                            else
                              cout<<"invalid patient ID.."<<endl;

                        }

                     }

                     if(ch4==3)
                     {
                         int pat_id;
                         cout<<"enter the id of the patient for showing the record..."<<endl;

                         cin>>pat_id;
                         int check5=0;
                         for(int i=1;i<=pat_n;i++)
                         {
                            check5=checkPatient(pat[i],pat_id);
                           if(check5==1)
                           {
                              showPatientRecord(pat[i]);
                           }
                         }
                         if(check5==0)
                          cout<<"invalid patient id.."<<endl;

                        

                     }
                    if(ch4==4)
                    {
                      cout<<"Enter the id of the patient for showing the bill"<<endl;
                      int pat_id;
                      cin>>pat_id;
                      int check5=0;
                      for(int i=1;i<=bill_n;i++)
                      {
                        check5=checkBill(bi[i],pat_id);
                        if(check5==1){
                          bi[i].showBill();
                          break;

                        }
                      }
                      if(check5==0)
                      {
                        cout<<"Invalid patient ID"<<endl;
                      }
                    }
                   }

                 }

                 break;


                 case 7:
                   cout<<"enter the pharmacist ID and password.."<<endl;
                   int phar_id,phar_pwd;
                   cin>>phar_id>>phar_pwd;

                   int check7;
                   check7=0;
                   for(int i=1;i<=phar_n;i++)
                   {
                    check7=checkPharmacist(phar[i],phar_id,phar_pwd);
                    if(check7==1)
                    {
                   cout<<"1. add Medicines\n2. sell medicine and update the bill\nenter your choice\n";
                   int ch5;
                   cin>>ch5;

                   if(ch5==1)
                   {
                      med_n++;
                      addMedicine(med[med_n]);
                   }

                   if(ch5==2)
                   {  for(i=1;i<=pm_n;i++)
                    {
                         int check9=checkPrescribedMedicine(pm[i]);

                         if(check9==1)
                         {
                           performPrescribedMedicine(pm[i]);

                           int med_id,patient_id;
                           cout<<"enter the medicine and the patient id ..."<<endl;//from the patient id find the bill clas  of the patient and t=from the medId find the medicine class.

                           cin>>med_id>>patient_id;

                             for(i=0;i<=med_n;i++)
                             {
                                int check10=checkMedicine(med[i],med_id);

                                if(check10==1)
                                {
                                    break;
                                }
                             }
                             int j;
                             for(j=0;j<=pat_n;j++)
                             {
                              int check11=checkPatient(pat[j],patient_id);
                              if(check11==1)
                                break;
                             }  

                             sellMedicine(med[i],pat[j]);   

                             for(j=0;j<=bill_n;j++)   
                             {
                               int check12=checkBill(bi[j],patient_id);
                               if(check12==1)
                               {
                                   updateBillByPharmacist(bi[j],med[i]);
                               }
                             }        
                         }

                   }

                 }
            
              }
            
             }
                 break;


                    case 8:
                     int pat_id,pat_pwd;
                     cout<<"enter patient id and password"<<endl;
                     cin>>pat_id,pat_pwd;

                     int check33=0;
                     for(int p=1;p<=pat_n;p++)
                     {
                      check33=checkPatient(pat[p],pat_id);

                      if(check33==1)
                      {
                        cout<<"1. showPatient record\n2. Paybill\n";

                        int gh;
                        cin>>gh;
                        if(gh==1)
                        {
                          showPatientRecord(pat[p]);
                        }
                        if(gh==2)
                        { int check34=0;
                          for(int b=1;b<=bill_n;b++)
                          {
                             check34=checkBill(bi[b],pat_n);
                             if(check34==1)
                             {
                              cout<<"Bill paid."<<endl;
                              payBill(bi[b]);
                             }
                          }
                        }
                      }
                     }  

                     if(check33==0)
                     cout<<"\ninvalid patient id or password\n";   
      
               }         

             }
              if(ch==9)
               break;
             }
            if(ch==9)
              break;
                
          }


       }
        if(check21==0)
        cout<<"invalid hospital id or password.."<<endl;
              
       break;  


                     
        case 5:
         exit(0);
              


         }

      }
   
   }
  else
    cout<<"\ninvalid admin id or password"<<endl;
    

}
