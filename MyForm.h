#pragma once    

#include <iostream>
#include <conio.h>
#include <stdio.h>   
#include<vector>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <signal.h> 
#include "MyForm2.h"
#include "Account_Settings.h"
#include <functional>

string doc_name;
string pat_name;
string doc_username;
string pat_username;
string pat_password;
string doctor_phone = "";
string Pat_gender;
string doc_password;
string pat_age;
string mail;
string randomCode;
string PASSWORD;
bool Capture;
struct Accounts {
    string username;
    string password;
    string email;
};
struct Diseases{
    string name;
    string info;
    vector<string> symps;
    string doc_name;
    string doc_phone;

}CurrentDisease;

string sympnum="0";
string disease_name;

string disease_info;
string symptom_info;
vector<string> allsymps;

vector<Diseases>Disease_Diagnosed;
vector<float> percentage_of_diagnosed_Disease;
vector<float> percentage_of_related_Disease;
vector<Diseases> Related_Diseases;
int index_self = 1;
int index_related = 1;
struct Doctors {
    string doc_name;
    Accounts account;
    string phone;
    char send_email;
    vector<Diseases> doc_diseases;
};
Doctors* CurrentDoctor;
struct Patient {
    string patient_name;
    Accounts account;
    char gender;
    int age;
    vector<string> Disease_History;
};
Patient* CurrentPatient;
int index_allPatients = 0, index_allDoctors = 0; //index to know the number of doctors and patients in database.
/*These are the intialization for the keys*/
string startchoice,
registerChoice,
loginChoice,
menuChoice;
int z = 0;    ////Disease index 
const int limit = 120;
string attemptedUserName, attemptedPassword;
string password;
int diseaseChoice;
//---------------------------Repeated functions--------------------------
//-------This funtion print a line and make the cmd Automatically shift to the next menu
void printSeprator();
void printSeprator_for_errors();
void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
    fflush(stdout);
}
//---------------------------Login Functions-----------------------------
void loginInput();
bool doctorLogin(Doctors doctors[], string attemptedUsername, string attemptedPassword, Doctors*& currDoctor, int index_doctor);
bool patientLogin(Patient patient1[], string attemptedUsername, string attemptedPassword, Patient*& currPatient, int index_patients);
//---------------------------Register function----------------------------
bool check_database(string username);
bool check_phone(string phone);
//----------------------------Patient's Funciotns-------------------------
vector<string> symptoms_patient_feeling = {};
void remove_symptom_from_all_Symptoms(Diseases dis, int index);
void remove_symptom_from_all_Symptoms(Diseases dis);
void remove_symptom_from_all_Disease(Diseases dis, int index);
void remove_Disease_from_all_Diseases(Diseases dis);
void extract_Symptoms();
void extract_New_Symptoms(Diseases NewDisease);
void extract_New_Symptoms_to_alldiseases(Diseases NewDisease);

//----------------------------Doctor's Funciotns--------------------------
int symptom_Choice = 0;
void remove_Symptom();
void extract_disease_to_doctor();
Doctors allDoctors[1000] = {};
Patient allPatients[1000] = {};
vector<Diseases> allDiseases = {};
vector<string> allSymptoms = {};

//----------------------------Text Handling Functions---------------------
void writeAllDoctors(Doctors allDoctors[]);//when quit
void writeAllDiseases(vector<Diseases> allDiseases);//when quit
void writeAllPatients(Patient allPatients[]);//when quit
void getAllDoctors(Doctors allDoctors[]);
void getAllPatients(Patient allPatients[]);
void getAllDiseases(vector<Diseases>* allDiseases);
//----------------------------------------Register functions--------------------------------------------------------

bool check_database(string username) {
    string org2 = "";
    for (int j = 0; j < username.size(); j++) {
        org2 += char(tolower(username[j]));
    }
    for (int i = 0; i < index_allDoctors; i++) {
        string org = "";
        for (int j = 0; j < allDoctors[i].account.username.size(); j++) {
            if (isalpha(allDoctors[i].account.username[j]))
                org += char(tolower(allDoctors[i].account.username[j]));
            else {
                org += allDoctors[i].account.username[j];
            }
        }
        if (org == org2) {
            return false;
        }
    }
    for (int i = 0; i < index_allPatients; i++) {
        string org = "";
        for (int j = 0; j < allPatients[i].account.username.size(); j++) {
            if (isalpha(allPatients[i].account.username[j]))
                org += char(tolower(allPatients[i].account.username[j]));
            else {
                org += allPatients[i].account.username[j];
            }
        }
        if (org == org2) {
            return false;
        }
    }
    return true;
}
bool check_phone(string phone) {
    for (int i = 0; i < index_allDoctors; i++) {

        if (allDoctors[i].phone == phone) {
            return false;
        }
    }
    return true;
}
bool check_database_email(string email) {
    for (int i = 0; i < index_allDoctors; i++) {
        if (email == allDoctors[i].account.email) {
            return false;
        }

    }
    for (int i = 0; i < index_allPatients; i++) {
        if (email == allPatients[i].account.email) {
            return false;
        }

    }
    return true;
}
//----------------------------------------Login functions-----------------------------------------------------------
//LoginMenu function Malhash lazma anymore bs keep it 3shan law 3oznaha
void loginInput() {
    do {
        CurrentDoctor = nullptr;
        CurrentPatient = nullptr;
        /* getpass function is to make typing of the user as asterik
        it return variable called password*/
        if (doctorLogin(allDoctors, attemptedUserName, attemptedPassword, CurrentDoctor, index_allDoctors)) {
            loginChoice = "1";
            break;
        }
        else if (patientLogin(allPatients, attemptedUserName, attemptedPassword, CurrentPatient, index_allPatients)) {
            loginChoice = "2";
            break;
        }
        else {
            cout << "Invalid username and password\n";
        }

    } while (true);
    /*
    I made loginChoice = 1 so that I enter doc menu
    This will be substituted with and if condition that will decied after checking data base*/
}
bool patientLogin(Patient patient1[], string attemptedUsername, string attemptedPassword, Patient*& currPatient, int index_patients) {
    for (int i = 0; i < index_patients; i++) {
        if (patient1[i].account.username == attemptedUsername) {
            if (patient1[i].account.password == attemptedPassword) {
                currPatient = &patient1[i];
                return true;
            }
        }
    }
    return false;
}
bool doctorLogin(Doctors doctors[], string attemptedUsername, string attemptedPassword, Doctors*& currDoctor, int index_doctor) {
    for (int i = 0; i < index_doctor; i++) {
        if (doctors[i].account.username == attemptedUsername) {
            if (doctors[i].account.password == attemptedPassword) {
                currDoctor = &doctors[i];
                return true;
            }
        }
    }
    return false;
}

//-----------------------------------------Patient's Funciotns------------------------------------------------------

string Logout_choice = "";
string Quit_choice = "";

//This is for removing symptom from diseases
void remove_symptom_from_all_Symptoms(Diseases dis, int index) {
    bool check = false;
    int j = 0;
    for (; j < allSymptoms.size(); j++) {
        if (allSymptoms[j] == dis.symps[index]) {
            check = true;
            break;
        }
    }
    if (check) {
        allSymptoms.erase(allSymptoms.begin() + j);
    }
}
void remove_symptom_from_all_Disease(Diseases dis, int index) {
    int f = 0;
    int i = 0;
    bool check1 = false;
    for (; f < allDiseases.size(); f++) {
        //bool check1 = false;
        if (allDiseases[f].name == dis.name) {
            for (; i < allDiseases[f].symps.size(); i++) {
                if (allDiseases[f].symps[i] == dis.symps[index]) {
                    check1 = true;
                    break;
                }

            }
            if (check1) break;
        }
    }
    if (check1) {
        allDiseases[f].symps.erase(allDiseases[f].symps.begin() + i);
    }
}
//This is for removing symptoms of removed disease from allsymptoms 
void remove_symptom_from_all_Symptoms(Diseases dis) {
    for (int i = 0; i < dis.symps.size(); i++) {
        int j = 0;
        bool check = false;
        for (; j < allSymptoms.size(); j++) {
            if (allSymptoms[j] == dis.symps[i]) {
                check = true;
                break;
            }
        }
        if (check) {
            allSymptoms.erase(allSymptoms.begin() + j);
        }
    }
}
void remove_Disease_from_all_Diseases(Diseases dis) {
    bool check = false;
    int j = 0;
    for (; j < allDiseases.size(); j++) {
        if (allDiseases[j].name == dis.name) {
            check = true;
            break;
        }
    }
    if (check) {
        allDiseases.erase(allDiseases.begin() + j);
    }
}
void extract_Symptoms() {
    bool check = true;
    for (int k = 0; k < allDiseases.size(); k++) {
        for (int i = 0; i < allDiseases[k].symps.size(); i++) {
            check = true;
            for (int j = 0; j < allSymptoms.size(); j++) {
                if (allSymptoms[j] == allDiseases[k].symps[i]) {
                    check = false;
                    break;
                }
            }
            if (check) {
                allSymptoms.push_back(allDiseases[k].symps[i]);
            }
        }
    }
}
void extract_New_Symptoms(Diseases NewDisease) {
    for (int i = 0; i < NewDisease.symps.size(); i++) {
        bool check = true;
        for (int j = 0; j < allSymptoms.size(); j++) {
            if (allSymptoms[j] == NewDisease.symps[i]) {
                check = false;
                break;
            }
        }
        if (check) {
            allSymptoms.push_back(NewDisease.symps[i]);
        }
    }
}
void extract_New_Symptoms_to_alldiseases(Diseases NewDisease) {
    int f = 0;
    bool check1 = true;

    for (; f < allDiseases.size(); f++) {
        bool check1 = true;
        if (allDiseases[f].name == NewDisease.name) {
            if (allDiseases[f].symps.size() > 0) {
                if (allDiseases[f].symps.size() < NewDisease.symps.size()) {
                    check1 = false;
                    break;//break from third loop
                }
            }

        }
    }

    if (check1) {
        allDiseases[f].symps.push_back(NewDisease.symps[NewDisease.symps.size() - 1]);
    }
}

//---------------------------------------Doctor's Functions---------------------------------------------------------

int index_symp=1;

       

void extract_disease_to_doctor() {
    for (int i = 0; i < allDiseases.size(); i++) {
        for (int k = 0; k < index_allDoctors; k++) {
            if (allDiseases[i].doc_phone == allDoctors[k].phone) {
                allDoctors[k].doc_diseases.push_back(allDiseases[i]);
            }

        }
    }
}

//This funtion print a line and make the cmd Automatically shift to the next menu
void printSeprator() {
    cout << "-------------------------------------------------------------------------------------\n";
    cout << "\033[2J\033[1;1H";
}
void printSeprator_for_errors() {
    cout << "-------------------------------------------------------------------------------------\n";

}

//-----------------------------------text handling---------------------------------------------------

string space2underscore(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == ' ')
            text[i] = '_';
    }
    return text;
}

string underscore2space(string text) {
    for (int i = 0; i < text.size(); i++) {
        if (text[i] == '_')
            text[i] = ' ';
    }
    return text;
}

void writeAllDoctors(Doctors allDoctors[]) {

    fstream file;
    file.open("doctors.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < index_allDoctors; i++) {
            file << space2underscore(allDoctors[i].doc_name) << endl;
            file << allDoctors[i].phone << endl;
            file << allDoctors[i].account.username << endl;
            file << allDoctors[i].account.password << endl;
            file << allDoctors[i].account.email << endl;
            file << allDoctors[i].send_email << endl;
        }
    }
    file.close();
}

void writeAllDiseases(vector<Diseases> allDiseases) {
    fstream file;
    file.open("diseases.txt", ios::out);
    if (file.is_open()) {
        for (int i = 0; i < allDiseases.size(); i++) {
            file << space2underscore(allDiseases[i].name) << endl;
            file << space2underscore(allDiseases[i].info) << endl;
            file << space2underscore(allDiseases[i].doc_name) << endl;
            file << allDiseases[i].doc_phone << endl;
            file << "symptoms" << endl;
            for (int k = 0; k < allDiseases[i].symps.size(); k++) {
                file << space2underscore(allDiseases[i].symps[k]) << endl;
            }
            file << ";" << endl;
        }
    }
    file.close();
}

void writeAllPatients(Patient allPatients[]) {
    fstream file;
        file.open("patients.txt", ios::out);
        if (file.is_open()) {
        for (int i = 0; i < index_allPatients; i++) {
            file << allPatients[i].age << endl;
            file << space2underscore(allPatients[i].patient_name) << endl;
            file << allPatients[i].account.username << endl;
            file << allPatients[i].account.password << endl;
            file << allPatients[i].account.email << endl;
            file << allPatients[i].gender << endl;
            file << "diseaseHistory" << endl;
            for (int j = 0; j < allPatients[i].Disease_History.size(); j++) {
                file << space2underscore(allPatients[i].Disease_History[j]) << endl;
            }
            file << ";" << endl;
        }
    }
    file.close();
}

void getAllDoctors(Doctors allDoctors[]) {
    fstream file;
    file.open("doctors.txt", ios::in);
    if (file.is_open()) {
        string line;
        while (file >> line) {
            Doctors* newDoctor = new Doctors();
            newDoctor->doc_name = underscore2space(line);
            file >> newDoctor->phone;
            file >> newDoctor->account.username;
            file >> newDoctor->account.password;
            file >> newDoctor->account.email;
            file >> newDoctor->send_email;
            allDoctors[index_allDoctors] = (*newDoctor);
            index_allDoctors++;
        }
    }
    file.close();
}

void getAllPatients(Patient allPatients[]) {
    fstream file;
    file.open("patients.txt", ios::in);
    if (file.is_open()) {
        string line;
        while (file >> line) {
            Patient* newPatient = new Patient();
            newPatient->age = stoi(line);
            file >> line;
            newPatient->patient_name = underscore2space(line);
            file >> newPatient->account.username;
            file >> newPatient->account.password;
            file >> newPatient->account.email;
            file >> newPatient->gender;
            string diseaseChecker;
            file >> diseaseChecker;
            while (diseaseChecker != ";") {
                file >> diseaseChecker;
                newPatient->Disease_History.push_back(underscore2space(diseaseChecker));
            }
            newPatient->Disease_History.pop_back();
            allPatients[index_allPatients] = (*newPatient);
            index_allPatients++;
        }
    }
    file.close();
}
void getAllDiseases(vector<Diseases>* allDiseases) {
    fstream file;
    file.open("diseases.txt", ios::in);
    if (file.is_open()) {
        string line;
        while (file >> line) {
            Diseases* newDisease = new Diseases();
            newDisease->name = underscore2space(line);
            file >> line;
            newDisease->info = underscore2space(line);
            file >> line;
            newDisease->doc_name = underscore2space(line);
            file >> newDisease->doc_phone;
            string symptomChecker;
            file >> symptomChecker;
            while (symptomChecker != ";") {
                file >> symptomChecker;
                newDisease->symps.push_back(underscore2space(symptomChecker));
            }
            newDisease->symps.pop_back();
            (*allDiseases).push_back(*newDisease);
        }
    }
    file.close();
}

namespace Project38 {
    static string to;
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
    using namespace System::Web;
    using namespace System::Net;
    using namespace System::Net::Mail;
    using namespace System::Windows::Forms;
    using namespace AForge;
    using namespace AForge::Video;
    using namespace AForge::Video::DirectShow;
    using namespace DarrenLee::Media;
    using namespace System::IO;
    using namespace System::Drawing::Imaging;
    using namespace System::Drawing::Drawing2D;

    //---------------------------Structures to work on--------------------------
	public ref class MyForm : public System::Windows::Forms::Form
	{
          


	public:
            

        Camera^ MyCamera = gcnew Camera();
        
        void MarshalString(String^ s, string& os) {
            using namespace Runtime::InteropServices;
            const char* chars =
                (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
            os = chars;
            Marshal::FreeHGlobal(IntPtr((void*)chars));
    }
        static String^ Code;
    private: System::Windows::Forms::PictureBox^ pictureBox31;
    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Label^ label34;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::PictureBox^ pictureBox32;
    private: System::Windows::Forms::PictureBox^ pictureBox33;
    private: System::Windows::Forms::Button^ Account_settings;
    public: event DarrenLee::Media::FrameArrivedEventHandler^ wow;
    public:
        bool button2_cliccked;
        MyForm(string pass)
        {
            InitializeComponent();
            PASSWORD = pass;
            //
            //TODO: Add the constructor code here
            //
        }
        MyForm(void)
        {
            InitializeComponent();
            
            
            
            MyCamera->OnFrameArrived += gcnew FrameArrivedEventHandler(this, &MyForm::MyCamera_OnFrameArrived);

            
            //
            //TODO: Add the constructor code here
            //
            
        }
        void MyCamera_OnFrameArrived(Object^ source, FrameArrivedEventArgs^ e) {
            Image^ img = e->GetFrame();
            pictureBox31->Image = img;
        }
//Patient--------------------------------------
void printPatientMenu() {
            String^ str2 = gcnew String((*CurrentPatient).patient_name.c_str());
            if ((*CurrentPatient).gender == 'f' || (*CurrentPatient).gender == 'F') {
                label15->Text = String::Format( "Hello Ms/Mrs.{0}", str2);
            }   
            else label15->Text = String::Format("Hello Mr.{0}", str2);
        }
void view_all_Symptoms() {
            label17->Text = "Please enter the symptoms you are currently feeling.\nWhen you are done, enter 0\n";
            label17->Show(); 
            label19->Text="";
            label19->Show();
            vector<string> symptoms_patient_feeling = {};
            for (int i = 1; i <= allSymptoms.size(); i++) {
                String^ str2 = gcnew String(allSymptoms[i - 1].c_str());
                String^ index = gcnew String(to_string(i).c_str());
                if (i % 5 == 0) {
                    label19->Text += String::Format("{0}.{1}\n", index, str2);
                }
                else
                    label19->Text += String::Format("{0}.{1}     ", index, str2);

            }
        }
void viewhist() {
    label19->Text = "";
    if ((*CurrentPatient).Disease_History.size() == 0)
       label19->Text+="You do not have a Diagnosis History";
    else {
        label19->Text+="The diseases you were diagnosed with are:\n";
        for (int i = 1; i <= (*CurrentPatient).Disease_History.size(); i++) {
            String^ index = gcnew String(to_string(i).c_str());
            String^ str2 = gcnew String((*CurrentPatient).Disease_History[i - 1].c_str());
            label19->Text+=String::Format("{0}-{1}\n",index,str2);
        }
    }
}
void selfdiagnosis() {

    
   
    bool check_duplicate = true;
    Disease_Diagnosed.clear();
    Related_Diseases.clear();

        percentage_of_diagnosed_Disease.clear();
        percentage_of_related_Disease.clear();




        for (int i = 0; i < allDiseases.size(); i++) {//iterate on diseases
            float percentage = 0;
            for (int j = 0; j < allDiseases[i].symps.size(); j++) {//iterate on symptoms of each disease
                for (int k = 0; k < symptoms_patient_feeling.size(); k++) {//iterates on the symptoms the patient is feeling
                    if (allSymptoms[stoi(symptoms_patient_feeling[k]) - 1] == allDiseases[i].symps[j]) {
                        percentage++;
                        break;
                    }
                }

            }

            if (percentage / allDiseases[i].symps.size() >= 0.6) {
                percentage /= allDiseases[i].symps.size();
                Disease_Diagnosed.push_back(allDiseases[i]);
                percentage_of_diagnosed_Disease.push_back(percentage);
            }
            else if (percentage / allDiseases[i].symps.size() > 0) {
                percentage /= allDiseases[i].symps.size();
                Related_Diseases.push_back(allDiseases[i]);
                percentage_of_related_Disease.push_back(percentage);
            }
        }

        if (Disease_Diagnosed.size() > 0) {
            for (int i = 0; i < Disease_Diagnosed.size(); i++) {
                for (int j = 0; j < (*CurrentPatient).Disease_History.size(); j++) {
                    if (Disease_Diagnosed[i].name == (*CurrentPatient).Disease_History[j]) {
                        check_duplicate = false;
                    }
                }
                if (check_duplicate) {

                    (*CurrentPatient).Disease_History.push_back(Disease_Diagnosed[i].name);
                }
            }
        }
         else if (Related_Diseases.size() > 0) {
            float max_value = -1;
            int max_index;
            vector<int> index_max;
            label17->Text="You are not diagnosed with any Diseases, but here is the closest disease related to your symptoms:\n";
            for (int i = 0; i < percentage_of_related_Disease.size(); i++) {
                if (percentage_of_related_Disease[i] > max_value) {
                    max_value = percentage_of_related_Disease[i];
                    max_index = i;
                }
            }
            index_max.push_back(max_index);
            max_index++;
            for (max_index; max_index < percentage_of_related_Disease.size(); max_index++) {
                if (percentage_of_related_Disease[max_index] == max_value) {
                    index_max.push_back(max_index);
                }
            }
            

      
        }
}
void display_Symptoms_for_Disease() {
    bool check_input;
    string x;
    label19->Text = "";
    label19->Show();
    for (int i = 1; i <= allDiseases.size(); i++) {
        String^ index = gcnew String(to_string(i).c_str());
        String^ str2 = gcnew String(allDiseases[i - 1].name.c_str());
        if (i % 10 == 0)
            label19->Text += String::Format("{0}-{1}\n", index, str2);
        else    label19->Text += String::Format("{0}-{1}      ", index, str2);
    }
    label17->Text = "please enter the number for the particular Disease.";
    label17->Show();
    textBox4->Text = "";
    textBox4->Show();
    button3->Text = "Next";
    button3->Show();
    




}
void extract_New_Symptoms_to_alldiseases(Diseases NewDisease) {
    int f = 0;
    for (; f < allDiseases.size(); f++) {
        if (allDiseases[f].name == NewDisease.name) {
            break;
        }
    }
        allDiseases[f].symps.push_back(NewDisease.symps[NewDisease.symps.size() - 1]);
}
//--------------------------------------------
//Doctor--------------------------------------
bool check_disease_name(string disease_name) {
    bool check = false;

    for (int i = 0; i < allDiseases.size(); i++) {
        int c = 0;
        if (allDiseases[i].name.size() == disease_name.size()) {
            for (int j = 0; j < allDiseases[i].name.size(); j++) {
                if (tolower(allDiseases[i].name[j]) == tolower(disease_name[j])) {
                    c++;
                }
                if (c == allDiseases[i].name.size()) {
                    break;
                }
            }
        }
        if (c == allDiseases[i].name.size()) {
            if ((*CurrentDoctor).phone == allDiseases[i].doc_phone) {
                label32->Text = "You have entered this disease before\n";
                label32->Show();
                return true;
            }
            else {
                String^ str2 = gcnew String(allDiseases[i].doc_name.c_str());
                String^ str3 = gcnew String(allDiseases[i].doc_phone.c_str());
                label32->Text = String::Format("Unfortunately this disease was added by Dr.{0}\nfor further info you can contact him on:",str2,str3 );
                label32->Show();
                return true;

            }
        }
    }
    return false;
}
void PrintDoctorMenu() {
    String^ str2 = gcnew String((*CurrentDoctor).doc_name.c_str());
    label30->Text= String::Format("Hello Dr.{0}", str2);
    string wow = "PICs\\Doctors\\" + (*CurrentDoctor).account.username + ".jpg";
    String^ str3 = gcnew String(wow.c_str());
    if (System::IO::File::Exists(str3)) {
        pictureBox32->ImageLocation = str3;
    }
    else {
        pictureBox32->ImageLocation = "PICs\\guest.jpg";
    } 
}
void display_All_diseases() {
    string choice;
    bool check;        int viewChoice = -1;
   label29->Text= "Choose the disease you want to view.";
   label29->Show();
   label28->Text = "";
   label28->Show();
   textBox4->Show();
    for (int i = 1; i <= allDiseases.size(); i++) {
        String^ str2 = gcnew String(allDiseases[i - 1].name.c_str());
        String^ index = gcnew String(to_string(i).c_str());
        if (i % 5 == 0 || i == allDiseases.size())
            label28->Text+=String::Format("{0}-{1}\n",index,str2);
        else
            label28->Text += String::Format("{0}-{1}     ", index, str2);
    }
}
void view_Patients() {
    bool check = true;
    string choice;
    int viewChoice = -1;
        label29->Text = "Which Disease you want to display its Patients?";
        label29->Show();
        label28->Text = "";
        textBox4->Show();
        for (int i = 1; i <= allDiseases.size(); i++) {
            String^ str2 = gcnew String(allDiseases[i - 1].name.c_str());
            String^ index = gcnew String(to_string(i).c_str());
            if (i % 5 == 0 || i == allDiseases.size())
                label28->Text += String::Format("{0}-{1}\n", index, str2);
            else
                label28->Text += String::Format("{0}-{1}     ", index, str2);
        }
        label28->Show();

}
void add_Symptom() {
    string choice;
    bool check = true;
    char choice_symptom = 'n';
    int iteration = 0;
    string symptom_info;
    //if the doctor doesn't have ant disease this if condition runs
    if ((*CurrentDoctor).doc_diseases.size() == 0) {
        label29->Text= "Unfortunately You haven't added any disease yet.";
        label29->Show();
        button4->Text = "End";
        textBox5->Hide();
        button6->Hide();
    }
    else {
       label29->Text= "Please choose Which disease you want\nto add its symptoms....";
       //This for loop is to display all diseases added by the doctor
       label28->Text = "";
       label29->Show();
        for (int i = 0; i < (*CurrentDoctor).doc_diseases.size(); i++) {
            String^ index = gcnew String(to_string(i+1).c_str());
            String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[i].name.c_str());
            if(i%5==0&&i!=0)  label28->Text += String::Format("{0}-{1}\n", index,str2);
            else label28->Text += String::Format("{0}-{1}     ", index, str2);
        }
        textBox5->Show();
        button6->Show();
        label28->Show();
    } // end of else
}
void remove_disease() {
    string choice;
    bool check = true;
    //if the doctor doesn't have ant disease this if condition runs
    if ((*CurrentDoctor).doc_diseases.size() == 0) {
        label29->Text="Unfortunately You haven't added any disease yet.\n";
        label29->Show();
        button4->Text = "End";
        textBox5->Hide();
        button6->Hide();
    }
    else {
        //This for loop is to display all diseases added by the doctor
        label28->Text = "";
        for (int i = 0; i < (*CurrentDoctor).doc_diseases.size(); i++) {
            String^ index = gcnew String(to_string(i + 1).c_str());
            String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[i].name.c_str());
            if (i % 5 == 0 && i != 0)  label28->Text += String::Format("{0}-{1}\n", index, str2);
            else label28->Text += String::Format("{0}-{1}     ", index, str2);
        }
        button4->Text = "Next";
        label28->Show();
        label29->Text = "Please choose Which disease you want to delete..";
        label29->Show();
        textBox5->Show();
        button6->Show();
        label28->Show();
    }
}
void remove_Symptom() {
    string choice;
    bool check = true;
    //if the doctor doesn't have ant disease this if condition runs
    if ((*CurrentDoctor).doc_diseases.size() == 0) {
        label29->Text = "Unfortunately You haven't added any disease yet.\n";
        label29->Show();
        button4->Text = "End";
        textBox5->Hide();
        button6->Hide();
    }
    else {
        //This for loop is to display all diseases added by the doctor
        label28->Text = "";
        for (int i = 0; i < (*CurrentDoctor).doc_diseases.size(); i++) {
            String^ index = gcnew String(to_string(i + 1).c_str());
            String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[i].name.c_str());
            if (i % 5 == 0 && i != 0)  label28->Text += String::Format("{0}-{1}\n", index, str2);
            else label28->Text += String::Format("{0}-{1}     ", index, str2);
        }
        button4->Text = "Next";
        label28->Show();
        label29->Text = "Please choose Which disease you want\nto delete its symptoms..";
        label29->Show();
        textBox5->Show();
        button6->Show();
        label28->Show();


       
    }//this is for the second else which runs when the symptoms are greater than 0
}
void logout_back() {
    Form::Width += 200;
    Form::Height += 150;
    timer2->Start();
    Sign_in->Text = "Sign-in";
    Register->Text = "Register";
    panel4->Hide();
    panel5->Hide();
    textBox1->Text = "";
    textBox2->Text = "";
}


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}

	protected:



   
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::Button^ Register;




	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Timer^ timer2;


	private: System::Windows::Forms::Label^ Username;
	private: System::Windows::Forms::Label^ Password;

	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Button^ Next;




	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::TextBox^ textBox3;

	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Panel^ panel1;

	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::Button^ Sign_in;
	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ pictureBox5;



	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ pictureBox7;
	private: System::Windows::Forms::PictureBox^ pictureBox2;

	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;



	private: System::Windows::Forms::PictureBox^ pictureBox8;
	private: System::Windows::Forms::PictureBox^ pictureBox9;
	internal: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::Label^ label3;

    private: System::Windows::Forms::Timer^ timer3;
    private: System::Windows::Forms::Label^ label7;
    private: System::Windows::Forms::Label^ label2;
    private: System::Windows::Forms::Panel^ panel3;
    private: System::Windows::Forms::PictureBox^ pictureBox1;
    private: System::Windows::Forms::Panel^ panel4;
    private: System::Windows::Forms::PictureBox^ pictureBox10;
    private: System::Windows::Forms::PictureBox^ pictureBox11;

    private: System::Windows::Forms::PictureBox^ pictureBox13;
    private: System::Windows::Forms::PictureBox^ pictureBox14;
    private: System::Windows::Forms::Label^ label8;
    private: System::Windows::Forms::Label^ label9;
    private: System::Windows::Forms::Label^ label12;
    private: System::Windows::Forms::PictureBox^ pictureBox15;
    private: System::Windows::Forms::PictureBox^ pictureBox16;
    private: System::Windows::Forms::PictureBox^ pictureBox17;
    private: System::Windows::Forms::Label^ label13;
    private: System::Windows::Forms::Label^ label14;
    private: System::Windows::Forms::Label^ label15;
    private: System::Windows::Forms::PictureBox^ pictureBox18;
    private: System::Windows::Forms::Label^ label16;
    private: System::Windows::Forms::Label^ label17;
private: System::Windows::Forms::TextBox^ textBox4;
private: System::Windows::Forms::Label^ label18;
private: System::Windows::Forms::Button^ button2;
private: System::Windows::Forms::Label^ label19;
private: System::Windows::Forms::Button^ button3;
private: System::Windows::Forms::Panel^ panel5;
private: System::Windows::Forms::PictureBox^ pictureBox19;
private: System::Windows::Forms::PictureBox^ pictureBox20;

private: System::Windows::Forms::PictureBox^ pictureBox22;
private: System::Windows::Forms::PictureBox^ pictureBox23;
private: System::Windows::Forms::PictureBox^ pictureBox24;
private: System::Windows::Forms::PictureBox^ pictureBox25;
private: System::Windows::Forms::Label^ label20;
private: System::Windows::Forms::Label^ label21;
private: System::Windows::Forms::Label^ label22;
private: System::Windows::Forms::Label^ label23;
private: System::Windows::Forms::PictureBox^ pictureBox26;
private: System::Windows::Forms::Label^ label24;
private: System::Windows::Forms::Label^ label25;
private: System::Windows::Forms::Label^ label26;
private: System::Windows::Forms::Label^ label27;
private: System::Windows::Forms::Label^ label30;
private: System::Windows::Forms::PictureBox^ pictureBox27;
private: System::Windows::Forms::PictureBox^ pictureBox28;
private: System::Windows::Forms::PictureBox^ pictureBox29;
private: System::Windows::Forms::Label^ label28;
private: System::Windows::Forms::Label^ label29;
private: System::Windows::Forms::TextBox^ textBox5;

private: System::Windows::Forms::PictureBox^ pictureBox21;
private: System::Windows::Forms::Button^ button6;

private: System::Windows::Forms::Button^ button4;
private: System::Windows::Forms::Label^ label32;
private: System::Windows::Forms::TextBox^ textBox6;
private: System::Windows::Forms::Label^ label31;
private: System::Windows::Forms::PictureBox^ pictureBox30;
private: System::Windows::Forms::PictureBox^ pictureBox12;
private: System::Windows::Forms::Button^ Back_P;
private: System::Windows::Forms::Button^ button7;
private: System::Windows::Forms::Label^ label33;
private: System::Windows::Forms::Button^ button5;



















    internal:
	private:

















	private: System::ComponentModel::IContainer^ components;






	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            this->components = (gcnew System::ComponentModel::Container());
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->Register = (gcnew System::Windows::Forms::Button());
            this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
            this->Username = (gcnew System::Windows::Forms::Label());
            this->Password = (gcnew System::Windows::Forms::Label());
            this->button1 = (gcnew System::Windows::Forms::Button());
            this->Next = (gcnew System::Windows::Forms::Button());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->panel2 = (gcnew System::Windows::Forms::Panel());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->panel1 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
            this->Sign_in = (gcnew System::Windows::Forms::Button());
            this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
            this->label4 = (gcnew System::Windows::Forms::Label());
            this->label5 = (gcnew System::Windows::Forms::Label());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox9 = (gcnew System::Windows::Forms::PictureBox());
            this->label10 = (gcnew System::Windows::Forms::Label());
            this->label11 = (gcnew System::Windows::Forms::Label());
            this->label3 = (gcnew System::Windows::Forms::Label());
            this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->Back_P = (gcnew System::Windows::Forms::Button());
            this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->Account_settings = (gcnew System::Windows::Forms::Button());
            this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
            this->label26 = (gcnew System::Windows::Forms::Label());
            this->pictureBox25 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox23 = (gcnew System::Windows::Forms::PictureBox());
            this->label24 = (gcnew System::Windows::Forms::Label());
            this->label22 = (gcnew System::Windows::Forms::Label());
            this->pictureBox22 = (gcnew System::Windows::Forms::PictureBox());
            this->label23 = (gcnew System::Windows::Forms::Label());
            this->pictureBox19 = (gcnew System::Windows::Forms::PictureBox());
            this->label25 = (gcnew System::Windows::Forms::Label());
            this->pictureBox24 = (gcnew System::Windows::Forms::PictureBox());
            this->label27 = (gcnew System::Windows::Forms::Label());
            this->pictureBox26 = (gcnew System::Windows::Forms::PictureBox());
            this->label31 = (gcnew System::Windows::Forms::Label());
            this->textBox6 = (gcnew System::Windows::Forms::TextBox());
            this->label32 = (gcnew System::Windows::Forms::Label());
            this->button6 = (gcnew System::Windows::Forms::Button());
            this->button4 = (gcnew System::Windows::Forms::Button());
            this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
            this->button3 = (gcnew System::Windows::Forms::Button());
            this->label19 = (gcnew System::Windows::Forms::Label());
            this->button2 = (gcnew System::Windows::Forms::Button());
            this->label18 = (gcnew System::Windows::Forms::Label());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->label17 = (gcnew System::Windows::Forms::Label());
            this->label16 = (gcnew System::Windows::Forms::Label());
            this->pictureBox10 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox11 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox13 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox14 = (gcnew System::Windows::Forms::PictureBox());
            this->label8 = (gcnew System::Windows::Forms::Label());
            this->label9 = (gcnew System::Windows::Forms::Label());
            this->label12 = (gcnew System::Windows::Forms::Label());
            this->pictureBox15 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox16 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox17 = (gcnew System::Windows::Forms::PictureBox());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->label14 = (gcnew System::Windows::Forms::Label());
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->BeginInit();
            this->panel3->SuspendLayout();
            this->panel4->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            this->panel5->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->SuspendLayout();
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->BackColor = System::Drawing::Color::Transparent;
            this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 36, System::Drawing::FontStyle::Bold));
            this->label1->ForeColor = System::Drawing::Color::White;
            this->label1->Location = System::Drawing::Point(2, 19);
            this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(1062, 81);
            this->label1->TabIndex = 5;
            this->label1->Text = L"Welcome to the self-diagnosis system";
            // 
            // Register
            // 
            this->Register->BackColor = System::Drawing::Color::Transparent;
            this->Register->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Register->Location = System::Drawing::Point(1921, 313);
            this->Register->Margin = System::Windows::Forms::Padding(2);
            this->Register->Name = L"Register";
            this->Register->Size = System::Drawing::Size(111, 42);
            this->Register->TabIndex = 7;
            this->Register->Text = L"Register";
            this->Register->UseVisualStyleBackColor = false;
            this->Register->Click += gcnew System::EventHandler(this, &MyForm::Register_Click);
            // 
            // timer1
            // 
            this->timer1->Interval = 1;
            this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
            // 
            // timer2
            // 
            this->timer2->Interval = 2;
            this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
            // 
            // Username
            // 
            this->Username->AutoSize = true;
            this->Username->BackColor = System::Drawing::Color::Transparent;
            this->Username->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Username->ForeColor = System::Drawing::Color::White;
            this->Username->Location = System::Drawing::Point(1245, 349);
            this->Username->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->Username->Name = L"Username";
            this->Username->Size = System::Drawing::Size(91, 23);
            this->Username->TabIndex = 11;
            this->Username->Text = L"Username:";
            // 
            // Password
            // 
            this->Password->AutoSize = true;
            this->Password->BackColor = System::Drawing::Color::Transparent;
            this->Password->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Password->ForeColor = System::Drawing::Color::White;
            this->Password->Location = System::Drawing::Point(1242, 438);
            this->Password->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->Password->Name = L"Password";
            this->Password->Size = System::Drawing::Size(86, 23);
            this->Password->TabIndex = 12;
            this->Password->Text = L"Password:";
            // 
            // button1
            // 
            this->button1->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button1->Location = System::Drawing::Point(1299, 590);
            this->button1->Name = L"button1";
            this->button1->Size = System::Drawing::Size(121, 39);
            this->button1->TabIndex = 14;
            this->button1->Text = L"Sign in";
            this->button1->UseVisualStyleBackColor = true;
            this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
            // 
            // Next
            // 
            this->Next->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Next->Location = System::Drawing::Point(1234, 590);
            this->Next->Name = L"Next";
            this->Next->Size = System::Drawing::Size(121, 39);
            this->Next->TabIndex = 15;
            this->Next->Text = L"NEXT";
            this->Next->UseVisualStyleBackColor = true;
            this->Next->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
            // 
            // textBox2
            // 
            this->textBox2->Location = System::Drawing::Point(1249, 477);
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(238, 24);
            this->textBox2->TabIndex = 20;
            this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox2_KeyDown);
            // 
            // panel2
            // 
            this->panel2->BackColor = System::Drawing::SystemColors::Desktop;
            this->panel2->Location = System::Drawing::Point(1249, 496);
            this->panel2->Name = L"panel2";
            this->panel2->Size = System::Drawing::Size(238, 5);
            this->panel2->TabIndex = 21;
            // 
            // textBox3
            // 
            this->textBox3->Location = System::Drawing::Point(1246, 392);
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(238, 24);
            this->textBox3->TabIndex = 22;
            this->textBox3->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox3_KeyDown);
            this->textBox3->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox3_KeyPress);
            // 
            // textBox1
            // 
            this->textBox1->Location = System::Drawing::Point(1246, 392);
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(238, 24);
            this->textBox1->TabIndex = 24;
            this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox1_KeyDown);
            // 
            // panel1
            // 
            this->panel1->BackColor = System::Drawing::SystemColors::Desktop;
            this->panel1->Location = System::Drawing::Point(1246, 415);
            this->panel1->Name = L"panel1";
            this->panel1->Size = System::Drawing::Size(238, 4);
            this->panel1->TabIndex = 25;
            // 
            // pictureBox3
            // 
            this->pictureBox3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox3.Image")));
            this->pictureBox3->Location = System::Drawing::Point(524, 103);
            this->pictureBox3->Name = L"pictureBox3";
            this->pictureBox3->Size = System::Drawing::Size(204, 203);
            this->pictureBox3->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox3->TabIndex = 27;
            this->pictureBox3->TabStop = false;
            this->pictureBox3->Click += gcnew System::EventHandler(this, &MyForm::pictureBox3_Click);
            this->pictureBox3->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::z);
            this->pictureBox3->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox3_MouseLeave);
            this->pictureBox3->MouseHover += gcnew System::EventHandler(this, &MyForm::pictureBox3_MouseHover);
            // 
            // Sign_in
            // 
            this->Sign_in->BackColor = System::Drawing::Color::Transparent;
            this->Sign_in->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->Sign_in->Location = System::Drawing::Point(1934, 313);
            this->Sign_in->Margin = System::Windows::Forms::Padding(2);
            this->Sign_in->Name = L"Sign_in";
            this->Sign_in->Size = System::Drawing::Size(111, 41);
            this->Sign_in->TabIndex = 6;
            this->Sign_in->Text = L"Sign-in";
            this->Sign_in->UseVisualStyleBackColor = false;
            this->Sign_in->Click += gcnew System::EventHandler(this, &MyForm::Sign_in_Click);
            // 
            // pictureBox4
            // 
            this->pictureBox4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.Image")));
            this->pictureBox4->Location = System::Drawing::Point(524, 312);
            this->pictureBox4->Name = L"pictureBox4";
            this->pictureBox4->Size = System::Drawing::Size(204, 274);
            this->pictureBox4->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox4->TabIndex = 28;
            this->pictureBox4->TabStop = false;
            this->pictureBox4->Click += gcnew System::EventHandler(this, &MyForm::pictureBox4_Click);
            this->pictureBox4->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox4_MouseLeave);
            this->pictureBox4->MouseHover += gcnew System::EventHandler(this, &MyForm::pictureBox4_MouseHover);
            // 
            // pictureBox5
            // 
            this->pictureBox5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.Image")));
            this->pictureBox5->Location = System::Drawing::Point(524, 592);
            this->pictureBox5->Name = L"pictureBox5";
            this->pictureBox5->Size = System::Drawing::Size(204, 226);
            this->pictureBox5->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox5->TabIndex = 29;
            this->pictureBox5->TabStop = false;
            this->pictureBox5->Click += gcnew System::EventHandler(this, &MyForm::pictureBox5_Click);
            this->pictureBox5->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox5_MouseLeave);
            this->pictureBox5->MouseHover += gcnew System::EventHandler(this, &MyForm::pictureBox5_MouseHover);
            // 
            // pictureBox6
            // 
            this->pictureBox6->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox6.Image")));
            this->pictureBox6->Location = System::Drawing::Point(1175, 392);
            this->pictureBox6->Name = L"pictureBox6";
            this->pictureBox6->Size = System::Drawing::Size(154, 192);
            this->pictureBox6->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox6->TabIndex = 30;
            this->pictureBox6->TabStop = false;
            this->pictureBox6->Click += gcnew System::EventHandler(this, &MyForm::pictureBox6_Click);
            this->pictureBox6->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox6_MouseLeave);
            this->pictureBox6->MouseHover += gcnew System::EventHandler(this, &MyForm::pictureBox6_MouseHover);
            // 
            // pictureBox7
            // 
            this->pictureBox7->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox7->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox7.Image")));
            this->pictureBox7->Location = System::Drawing::Point(1355, 378);
            this->pictureBox7->Name = L"pictureBox7";
            this->pictureBox7->Size = System::Drawing::Size(160, 208);
            this->pictureBox7->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox7->TabIndex = 31;
            this->pictureBox7->TabStop = false;
            this->pictureBox7->Click += gcnew System::EventHandler(this, &MyForm::pictureBox7_Click);
            this->pictureBox7->MouseLeave += gcnew System::EventHandler(this, &MyForm::pictureBox7_MouseLeave);
            this->pictureBox7->MouseHover += gcnew System::EventHandler(this, &MyForm::pictureBox7_MouseHover);
            // 
            // pictureBox2
            // 
            this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
            this->pictureBox2->Location = System::Drawing::Point(1112, 191);
            this->pictureBox2->Name = L"pictureBox2";
            this->pictureBox2->Size = System::Drawing::Size(573, 488);
            this->pictureBox2->TabIndex = 32;
            this->pictureBox2->TabStop = false;
            this->pictureBox2->Click += gcnew System::EventHandler(this, &MyForm::pictureBox2_Click_1);
            // 
            // label4
            // 
            this->label4->AutoSize = true;
            this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16, System::Drawing::FontStyle::Bold));
            this->label4->ForeColor = System::Drawing::Color::Snow;
            this->label4->Location = System::Drawing::Point(1385, 295);
            this->label4->Name = L"label4";
            this->label4->Size = System::Drawing::Size(120, 37);
            this->label4->TabIndex = 34;
            this->label4->Text = L"PATIENT";
            this->label4->Click += gcnew System::EventHandler(this, &MyForm::label4_Click);
            // 
            // label5
            // 
            this->label5->AutoSize = true;
            this->label5->Font = (gcnew System::Drawing::Font(L"Tahoma", 30));
            this->label5->ForeColor = System::Drawing::SystemColors::Info;
            this->label5->Location = System::Drawing::Point(238, 180);
            this->label5->Name = L"label5";
            this->label5->Size = System::Drawing::Size(208, 60);
            this->label5->TabIndex = 35;
            this->label5->Text = L"SIGN-IN";
            // 
            // label6
            // 
            this->label6->AutoSize = true;
            this->label6->Font = (gcnew System::Drawing::Font(L"Tahoma", 30));
            this->label6->ForeColor = System::Drawing::SystemColors::Info;
            this->label6->Location = System::Drawing::Point(238, 402);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(252, 60);
            this->label6->TabIndex = 36;
            this->label6->Text = L"REGISTER";
            this->label6->Click += gcnew System::EventHandler(this, &MyForm::label6_Click);
            // 
            // pictureBox8
            // 
            this->pictureBox8->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox8->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox8.Image")));
            this->pictureBox8->Location = System::Drawing::Point(1355, 378);
            this->pictureBox8->Name = L"pictureBox8";
            this->pictureBox8->Size = System::Drawing::Size(181, 210);
            this->pictureBox8->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox8->TabIndex = 40;
            this->pictureBox8->TabStop = false;
            this->pictureBox8->Click += gcnew System::EventHandler(this, &MyForm::pictureBox8_Click);
            // 
            // pictureBox9
            // 
            this->pictureBox9->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox9->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox9.Image")));
            this->pictureBox9->Location = System::Drawing::Point(1168, 376);
            this->pictureBox9->Name = L"pictureBox9";
            this->pictureBox9->Size = System::Drawing::Size(181, 210);
            this->pictureBox9->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox9->TabIndex = 41;
            this->pictureBox9->TabStop = false;
            this->pictureBox9->Click += gcnew System::EventHandler(this, &MyForm::pictureBox9_Click);
            // 
            // label10
            // 
            this->label10->AutoSize = true;
            this->label10->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16, System::Drawing::FontStyle::Bold));
            this->label10->ForeColor = System::Drawing::Color::Snow;
            this->label10->Location = System::Drawing::Point(1278, 258);
            this->label10->Name = L"label10";
            this->label10->Size = System::Drawing::Size(121, 37);
            this->label10->TabIndex = 42;
            this->label10->Text = L"GENDER";
            // 
            // label11
            // 
            this->label11->AutoSize = true;
            this->label11->Location = System::Drawing::Point(1931, 373);
            this->label11->Name = L"label11";
            this->label11->Size = System::Drawing::Size(50, 17);
            this->label11->TabIndex = 43;
            this->label11->Text = L"label11";
            // 
            // label3
            // 
            this->label3->AutoSize = true;
            this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 16, System::Drawing::FontStyle::Bold));
            this->label3->ForeColor = System::Drawing::Color::Snow;
            this->label3->Location = System::Drawing::Point(1193, 295);
            this->label3->Name = L"label3";
            this->label3->Size = System::Drawing::Size(124, 37);
            this->label3->TabIndex = 33;
            this->label3->Text = L"DOCTOR";
            // 
            // timer3
            // 
            this->timer3->Tick += gcnew System::EventHandler(this, &MyForm::timer3_Tick);
            // 
            // label7
            // 
            this->label7->AutoSize = true;
            this->label7->Font = (gcnew System::Drawing::Font(L"Tahoma", 30));
            this->label7->ForeColor = System::Drawing::SystemColors::Info;
            this->label7->Location = System::Drawing::Point(263, 657);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(141, 60);
            this->label7->TabIndex = 37;
            this->label7->Text = L"QUIT";
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Location = System::Drawing::Point(1175, 312);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(42, 17);
            this->label2->TabIndex = 13;
            this->label2->Text = L"label2";
            this->label2->Click += gcnew System::EventHandler(this, &MyForm::label2_Click);
            // 
            // panel3
            // 
            this->panel3->Controls->Add(this->button9);
            this->panel3->Controls->Add(this->button8);
            this->panel3->Controls->Add(this->label34);
            this->panel3->Controls->Add(this->button5);
            this->panel3->Controls->Add(this->label33);
            this->panel3->Controls->Add(this->panel4);
            this->panel3->Controls->Add(this->textBox1);
            this->panel3->Controls->Add(this->label1);
            this->panel3->Controls->Add(this->label5);
            this->panel3->Controls->Add(this->label10);
            this->panel3->Controls->Add(this->pictureBox3);
            this->panel3->Controls->Add(this->label6);
            this->panel3->Controls->Add(this->pictureBox4);
            this->panel3->Controls->Add(this->label4);
            this->panel3->Controls->Add(this->label7);
            this->panel3->Controls->Add(this->label3);
            this->panel3->Controls->Add(this->pictureBox5);
            this->panel3->Controls->Add(this->Username);
            this->panel3->Controls->Add(this->Password);
            this->panel3->Controls->Add(this->panel1);
            this->panel3->Controls->Add(this->label2);
            this->panel3->Controls->Add(this->button1);
            this->panel3->Controls->Add(this->textBox3);
            this->panel3->Controls->Add(this->Next);
            this->panel3->Controls->Add(this->panel2);
            this->panel3->Controls->Add(this->textBox2);
            this->panel3->Controls->Add(this->pictureBox1);
            this->panel3->Controls->Add(this->pictureBox2);
            this->panel3->Controls->Add(this->pictureBox9);
            this->panel3->Controls->Add(this->pictureBox6);
            this->panel3->Controls->Add(this->pictureBox8);
            this->panel3->Controls->Add(this->pictureBox7);
            this->panel3->Location = System::Drawing::Point(1, 0);
            this->panel3->Name = L"panel3";
            this->panel3->Size = System::Drawing::Size(1896, 835);
            this->panel3->TabIndex = 44;
            this->panel3->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel3_Paint);
            // 
            // button9
            // 
            this->button9->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button9->Location = System::Drawing::Point(1157, 507);
            this->button9->Name = L"button9";
            this->button9->Size = System::Drawing::Size(80, 44);
            this->button9->TabIndex = 56;
            this->button9->Text = L"BROWSE";
            this->button9->UseVisualStyleBackColor = true;
            this->button9->Click += gcnew System::EventHandler(this, &MyForm::button9_Click);
            // 
            // button8
            // 
            this->button8->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button8->Location = System::Drawing::Point(1456, 507);
            this->button8->Name = L"button8";
            this->button8->Size = System::Drawing::Size(80, 44);
            this->button8->TabIndex = 55;
            this->button8->Text = L"No Profile Picture";
            this->button8->UseVisualStyleBackColor = true;
            this->button8->Click += gcnew System::EventHandler(this, &MyForm::button8_Click);
            // 
            // label34
            // 
            this->label34->AutoSize = true;
            this->label34->Font = (gcnew System::Drawing::Font(L"Tahoma", 15, System::Drawing::FontStyle::Bold));
            this->label34->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->label34->Location = System::Drawing::Point(1163, 225);
            this->label34->Name = L"label34";
            this->label34->Size = System::Drawing::Size(201, 30);
            this->label34->TabIndex = 54;
            this->label34->Text = L"Profile Picture:";
            // 
            // button5
            // 
            this->button5->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button5->Location = System::Drawing::Point(1366, 590);
            this->button5->Name = L"button5";
            this->button5->Size = System::Drawing::Size(121, 39);
            this->button5->TabIndex = 52;
            this->button5->Text = L"BACK";
            this->button5->UseVisualStyleBackColor = true;
            this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_2);
            // 
            // label33
            // 
            this->label33->AutoSize = true;
            this->label33->Cursor = System::Windows::Forms::Cursors::Hand;
            this->label33->Font = (gcnew System::Drawing::Font(L"Tahoma", 8, System::Drawing::FontStyle::Underline));
            this->label33->Location = System::Drawing::Point(1248, 516);
            this->label33->Name = L"label33";
            this->label33->Size = System::Drawing::Size(151, 17);
            this->label33->TabIndex = 51;
            this->label33->Text = L"Forgot Your Password\?";
            this->label33->Click += gcnew System::EventHandler(this, &MyForm::label33_Click);
            this->label33->MouseLeave += gcnew System::EventHandler(this, &MyForm::label33_MouseLeave);
            this->label33->MouseHover += gcnew System::EventHandler(this, &MyForm::label33_MouseHover);
            // 
            // panel4
            // 
            this->panel4->Controls->Add(this->button7);
            this->panel4->Controls->Add(this->Back_P);
            this->panel4->Controls->Add(this->pictureBox12);
            this->panel4->Controls->Add(this->panel5);
            this->panel4->Controls->Add(this->button3);
            this->panel4->Controls->Add(this->label19);
            this->panel4->Controls->Add(this->button2);
            this->panel4->Controls->Add(this->label18);
            this->panel4->Controls->Add(this->textBox4);
            this->panel4->Controls->Add(this->label17);
            this->panel4->Controls->Add(this->label16);
            this->panel4->Controls->Add(this->pictureBox10);
            this->panel4->Controls->Add(this->pictureBox11);
            this->panel4->Controls->Add(this->pictureBox13);
            this->panel4->Controls->Add(this->pictureBox14);
            this->panel4->Controls->Add(this->label8);
            this->panel4->Controls->Add(this->label9);
            this->panel4->Controls->Add(this->label12);
            this->panel4->Controls->Add(this->pictureBox15);
            this->panel4->Controls->Add(this->pictureBox16);
            this->panel4->Controls->Add(this->pictureBox17);
            this->panel4->Controls->Add(this->label13);
            this->panel4->Controls->Add(this->label14);
            this->panel4->Controls->Add(this->label15);
            this->panel4->Controls->Add(this->pictureBox18);
            this->panel4->Dock = System::Windows::Forms::DockStyle::Fill;
            this->panel4->Location = System::Drawing::Point(0, 0);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(1896, 835);
            this->panel4->TabIndex = 50;
            // 
            // button7
            // 
            this->button7->Location = System::Drawing::Point(217, 154);
            this->button7->Name = L"button7";
            this->button7->Size = System::Drawing::Size(75, 23);
            this->button7->TabIndex = 51;
            this->button7->Text = L"button5";
            this->button7->UseVisualStyleBackColor = true;
            this->button7->Click += gcnew System::EventHandler(this, &MyForm::button5_Click_1);
            // 
            // Back_P
            // 
            this->Back_P->Cursor = System::Windows::Forms::Cursors::Hand;
            this->Back_P->Location = System::Drawing::Point(230, 504);
            this->Back_P->Name = L"Back_P";
            this->Back_P->Size = System::Drawing::Size(108, 35);
            this->Back_P->TabIndex = 50;
            this->Back_P->Text = L"Back";
            this->Back_P->UseVisualStyleBackColor = true;
            this->Back_P->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
            // 
            // pictureBox12
            // 
            this->pictureBox12->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox12->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox12.Image")));
            this->pictureBox12->Location = System::Drawing::Point(870, 94);
            this->pictureBox12->Name = L"pictureBox12";
            this->pictureBox12->Size = System::Drawing::Size(71, 75);
            this->pictureBox12->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox12->TabIndex = 49;
            this->pictureBox12->TabStop = false;
            this->pictureBox12->Click += gcnew System::EventHandler(this, &MyForm::pictureBox12_Click_1);
            // 
            // panel5
            // 
            this->panel5->Controls->Add(this->Account_settings);
            this->panel5->Controls->Add(this->pictureBox33);
            this->panel5->Controls->Add(this->pictureBox32);
            this->panel5->Controls->Add(this->pictureBox30);
            this->panel5->Controls->Add(this->pictureBox31);
            this->panel5->Controls->Add(this->label26);
            this->panel5->Controls->Add(this->pictureBox25);
            this->panel5->Controls->Add(this->pictureBox23);
            this->panel5->Controls->Add(this->label24);
            this->panel5->Controls->Add(this->label22);
            this->panel5->Controls->Add(this->pictureBox22);
            this->panel5->Controls->Add(this->label23);
            this->panel5->Controls->Add(this->pictureBox19);
            this->panel5->Controls->Add(this->label25);
            this->panel5->Controls->Add(this->pictureBox24);
            this->panel5->Controls->Add(this->label27);
            this->panel5->Controls->Add(this->pictureBox26);
            this->panel5->Controls->Add(this->label31);
            this->panel5->Controls->Add(this->textBox6);
            this->panel5->Controls->Add(this->label32);
            this->panel5->Controls->Add(this->button6);
            this->panel5->Controls->Add(this->button4);
            this->panel5->Controls->Add(this->pictureBox21);
            this->panel5->Controls->Add(this->textBox5);
            this->panel5->Controls->Add(this->label29);
            this->panel5->Controls->Add(this->label28);
            this->panel5->Controls->Add(this->pictureBox29);
            this->panel5->Controls->Add(this->pictureBox28);
            this->panel5->Controls->Add(this->pictureBox20);
            this->panel5->Controls->Add(this->label20);
            this->panel5->Controls->Add(this->label21);
            this->panel5->Controls->Add(this->label30);
            this->panel5->Controls->Add(this->pictureBox27);
            this->panel5->Location = System::Drawing::Point(0, 0);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(1896, 735);
            this->panel5->TabIndex = 48;
            this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint);
            // 
            // Account_settings
            // 
            this->Account_settings->Location = System::Drawing::Point(901, 13);
            this->Account_settings->Name = L"Account_settings";
            this->Account_settings->Size = System::Drawing::Size(96, 51);
            this->Account_settings->TabIndex = 56;
            this->Account_settings->Text = L"Account settings";
            this->Account_settings->UseVisualStyleBackColor = true;
            this->Account_settings->Click += gcnew System::EventHandler(this, &MyForm::Account_settings_Click);
            // 
            // pictureBox33
            // 
            this->pictureBox33->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox33.Image")));
            this->pictureBox33->Location = System::Drawing::Point(1109, 275);
            this->pictureBox33->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox33->Name = L"pictureBox33";
            this->pictureBox33->Size = System::Drawing::Size(253, 345);
            this->pictureBox33->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox33->TabIndex = 55;
            this->pictureBox33->TabStop = false;
            this->pictureBox33->Click += gcnew System::EventHandler(this, &MyForm::pictureBox33_Click);
            // 
            // pictureBox32
            // 
            this->pictureBox32->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox32->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox32.Image")));
            this->pictureBox32->Location = System::Drawing::Point(1186, 7);
            this->pictureBox32->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox32->Name = L"pictureBox32";
            this->pictureBox32->Size = System::Drawing::Size(71, 66);
            this->pictureBox32->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox32->TabIndex = 54;
            this->pictureBox32->TabStop = false;
            this->pictureBox32->Click += gcnew System::EventHandler(this, &MyForm::pictureBox32_Click);
            // 
            // pictureBox30
            // 
            this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.Image")));
            this->pictureBox30->Location = System::Drawing::Point(585, 271);
            this->pictureBox30->Name = L"pictureBox30";
            this->pictureBox30->Size = System::Drawing::Size(179, 142);
            this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox30->TabIndex = 53;
            this->pictureBox30->TabStop = false;
            this->pictureBox30->Click += gcnew System::EventHandler(this, &MyForm::pictureBox30_Click);
            // 
            // pictureBox31
            // 
            this->pictureBox31->Location = System::Drawing::Point(1157, 225);
            this->pictureBox31->Name = L"pictureBox31";
            this->pictureBox31->Size = System::Drawing::Size(379, 326);
            this->pictureBox31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox31->TabIndex = 53;
            this->pictureBox31->TabStop = false;
            this->pictureBox31->Click += gcnew System::EventHandler(this, &MyForm::pictureBox31_Click);
            // 
            // label26
            // 
            this->label26->AutoSize = true;
            this->label26->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label26->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label26->ForeColor = System::Drawing::Color::White;
            this->label26->Location = System::Drawing::Point(931, 217);
            this->label26->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label26->Name = L"label26";
            this->label26->Size = System::Drawing::Size(133, 23);
            this->label26->TabIndex = 25;
            this->label26->Text = L"Remove disease";
            // 
            // pictureBox25
            // 
            this->pictureBox25->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox25->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox25.Image")));
            this->pictureBox25->Location = System::Drawing::Point(816, 232);
            this->pictureBox25->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox25->Name = L"pictureBox25";
            this->pictureBox25->Size = System::Drawing::Size(86, 78);
            this->pictureBox25->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox25->TabIndex = 33;
            this->pictureBox25->TabStop = false;
            this->pictureBox25->Click += gcnew System::EventHandler(this, &MyForm::pictureBox25_Click);
            // 
            // pictureBox23
            // 
            this->pictureBox23->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox23->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox23.Image")));
            this->pictureBox23->Location = System::Drawing::Point(451, 378);
            this->pictureBox23->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox23->Name = L"pictureBox23";
            this->pictureBox23->Size = System::Drawing::Size(74, 89);
            this->pictureBox23->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox23->TabIndex = 35;
            this->pictureBox23->TabStop = false;
            this->pictureBox23->Click += gcnew System::EventHandler(this, &MyForm::pictureBox23_Click);
            // 
            // label24
            // 
            this->label24->AutoSize = true;
            this->label24->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label24->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label24->ForeColor = System::Drawing::Color::White;
            this->label24->Location = System::Drawing::Point(141, 475);
            this->label24->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label24->Name = L"label24";
            this->label24->Size = System::Drawing::Size(266, 23);
            this->label24->TabIndex = 27;
            this->label24->Text = L"Remove symptoms form diseases";
            // 
            // label22
            // 
            this->label22->AutoSize = true;
            this->label22->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label22->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label22->ForeColor = System::Drawing::Color::White;
            this->label22->Location = System::Drawing::Point(931, 465);
            this->label22->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label22->Name = L"label22";
            this->label22->Size = System::Drawing::Size(282, 23);
            this->label22->TabIndex = 30;
            this->label22->Text = L"View patients with a certain disease";
            // 
            // pictureBox22
            // 
            this->pictureBox22->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox22->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox22.Image")));
            this->pictureBox22->Location = System::Drawing::Point(816, 373);
            this->pictureBox22->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox22->Name = L"pictureBox22";
            this->pictureBox22->Size = System::Drawing::Size(69, 75);
            this->pictureBox22->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox22->TabIndex = 36;
            this->pictureBox22->TabStop = false;
            this->pictureBox22->Click += gcnew System::EventHandler(this, &MyForm::pictureBox22_Click);
            // 
            // label23
            // 
            this->label23->AutoSize = true;
            this->label23->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label23->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label23->ForeColor = System::Drawing::Color::White;
            this->label23->Location = System::Drawing::Point(598, 596);
            this->label23->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label23->Name = L"label23";
            this->label23->Size = System::Drawing::Size(154, 23);
            this->label23->TabIndex = 29;
            this->label23->Text = L"Display all diseases";
            // 
            // pictureBox19
            // 
            this->pictureBox19->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox19->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox19.Image")));
            this->pictureBox19->Location = System::Drawing::Point(641, 454);
            this->pictureBox19->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox19->Name = L"pictureBox19";
            this->pictureBox19->Size = System::Drawing::Size(65, 74);
            this->pictureBox19->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox19->TabIndex = 39;
            this->pictureBox19->TabStop = false;
            this->pictureBox19->Click += gcnew System::EventHandler(this, &MyForm::pictureBox19_Click);
            // 
            // label25
            // 
            this->label25->AutoSize = true;
            this->label25->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label25->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label25->ForeColor = System::Drawing::Color::White;
            this->label25->Location = System::Drawing::Point(194, 217);
            this->label25->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label25->Name = L"label25";
            this->label25->Size = System::Drawing::Size(213, 23);
            this->label25->TabIndex = 26;
            this->label25->Text = L"Add symptoms to diseases";
            // 
            // pictureBox24
            // 
            this->pictureBox24->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox24->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox24.Image")));
            this->pictureBox24->Location = System::Drawing::Point(451, 220);
            this->pictureBox24->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox24->Name = L"pictureBox24";
            this->pictureBox24->Size = System::Drawing::Size(82, 77);
            this->pictureBox24->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox24->TabIndex = 34;
            this->pictureBox24->TabStop = false;
            this->pictureBox24->Click += gcnew System::EventHandler(this, &MyForm::pictureBox24_Click);
            // 
            // label27
            // 
            this->label27->AutoSize = true;
            this->label27->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label27->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label27->ForeColor = System::Drawing::Color::White;
            this->label27->Location = System::Drawing::Point(626, 111);
            this->label27->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label27->Name = L"label27";
            this->label27->Size = System::Drawing::Size(101, 23);
            this->label27->TabIndex = 24;
            this->label27->Text = L"Add disease";
            // 
            // pictureBox26
            // 
            this->pictureBox26->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox26->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox26.Image")));
            this->pictureBox26->Location = System::Drawing::Point(630, 152);
            this->pictureBox26->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox26->Name = L"pictureBox26";
            this->pictureBox26->Size = System::Drawing::Size(85, 80);
            this->pictureBox26->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox26->TabIndex = 28;
            this->pictureBox26->TabStop = false;
            this->pictureBox26->Click += gcnew System::EventHandler(this, &MyForm::pictureBox26_Click);
            // 
            // label31
            // 
            this->label31->AutoSize = true;
            this->label31->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 22));
            this->label31->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->label31->Location = System::Drawing::Point(93, 330);
            this->label31->Name = L"label31";
            this->label31->Size = System::Drawing::Size(207, 50);
            this->label31->TabIndex = 52;
            this->label31->Text = L"wEEEeeeee";
            // 
            // textBox6
            // 
            this->textBox6->Cursor = System::Windows::Forms::Cursors::IBeam;
            this->textBox6->Location = System::Drawing::Point(89, 552);
            this->textBox6->Name = L"textBox6";
            this->textBox6->Size = System::Drawing::Size(207, 24);
            this->textBox6->TabIndex = 51;
            // 
            // label32
            // 
            this->label32->AutoSize = true;
            this->label32->Location = System::Drawing::Point(93, 522);
            this->label32->Name = L"label32";
            this->label32->Size = System::Drawing::Size(50, 17);
            this->label32->TabIndex = 50;
            this->label32->Text = L"label32";
            // 
            // button6
            // 
            this->button6->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button6->Location = System::Drawing::Point(198, 582);
            this->button6->Name = L"button6";
            this->button6->Size = System::Drawing::Size(87, 39);
            this->button6->TabIndex = 49;
            this->button6->Text = L"Back";
            this->button6->UseVisualStyleBackColor = true;
            this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
            // 
            // button4
            // 
            this->button4->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button4->Location = System::Drawing::Point(106, 582);
            this->button4->Name = L"button4";
            this->button4->Size = System::Drawing::Size(86, 38);
            this->button4->TabIndex = 47;
            this->button4->Text = L"Next";
            this->button4->UseVisualStyleBackColor = true;
            this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
            // 
            // pictureBox21
            // 
            this->pictureBox21->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox21.Image")));
            this->pictureBox21->Location = System::Drawing::Point(1200, 172);
            this->pictureBox21->Name = L"pictureBox21";
            this->pictureBox21->Size = System::Drawing::Size(50, 50);
            this->pictureBox21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
            this->pictureBox21->TabIndex = 46;
            this->pictureBox21->TabStop = false;
            this->pictureBox21->Click += gcnew System::EventHandler(this, &MyForm::pictureBox21_Click_1);
            // 
            // textBox5
            // 
            this->textBox5->Location = System::Drawing::Point(89, 552);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(207, 24);
            this->textBox5->TabIndex = 45;
            this->textBox5->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox5_KeyPress);
            // 
            // label29
            // 
            this->label29->AutoSize = true;
            this->label29->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 28));
            this->label29->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->label29->Location = System::Drawing::Point(78, 93);
            this->label29->Name = L"label29";
            this->label29->Size = System::Drawing::Size(135, 62);
            this->label29->TabIndex = 43;
            this->label29->Text = L"wEEE";
            // 
            // label28
            // 
            this->label28->AutoSize = true;
            this->label28->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
            this->label28->ForeColor = System::Drawing::SystemColors::ControlLightLight;
            this->label28->Location = System::Drawing::Point(82, 232);
            this->label28->Name = L"label28";
            this->label28->Size = System::Drawing::Size(89, 41);
            this->label28->TabIndex = 42;
            this->label28->Text = L"wEEE";
            this->label28->Click += gcnew System::EventHandler(this, &MyForm::label28_Click);
            // 
            // pictureBox29
            // 
            this->pictureBox29->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox29.Image")));
            this->pictureBox29->Location = System::Drawing::Point(375, 134);
            this->pictureBox29->Name = L"pictureBox29";
            this->pictureBox29->Size = System::Drawing::Size(594, 422);
            this->pictureBox29->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox29->TabIndex = 41;
            this->pictureBox29->TabStop = false;
            // 
            // pictureBox28
            // 
            this->pictureBox28->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox28.Image")));
            this->pictureBox28->Location = System::Drawing::Point(291, 77);
            this->pictureBox28->Name = L"pictureBox28";
            this->pictureBox28->Size = System::Drawing::Size(753, 523);
            this->pictureBox28->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox28->TabIndex = 40;
            this->pictureBox28->TabStop = false;
            this->pictureBox28->Click += gcnew System::EventHandler(this, &MyForm::pictureBox28_Click);
            // 
            // pictureBox20
            // 
            this->pictureBox20->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
            this->pictureBox20->Location = System::Drawing::Point(1207, 97);
            this->pictureBox20->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox20->Name = L"pictureBox20";
            this->pictureBox20->Size = System::Drawing::Size(50, 50);
            this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
            this->pictureBox20->TabIndex = 38;
            this->pictureBox20->TabStop = false;
            this->pictureBox20->Click += gcnew System::EventHandler(this, &MyForm::pictureBox20_Click);
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label20->ForeColor = System::Drawing::Color::White;
            this->label20->Location = System::Drawing::Point(1264, 111);
            this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(64, 23);
            this->label20->TabIndex = 32;
            this->label20->Text = L"Logout";
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label21->ForeColor = System::Drawing::Color::White;
            this->label21->Location = System::Drawing::Point(1255, 180);
            this->label21->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(43, 23);
            this->label21->TabIndex = 31;
            this->label21->Text = L"Quit";
            // 
            // label30
            // 
            this->label30->AutoSize = true;
            this->label30->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label30->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 32, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label30->ForeColor = System::Drawing::Color::White;
            this->label30->Location = System::Drawing::Point(4, 9);
            this->label30->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label30->Name = L"label30";
            this->label30->Size = System::Drawing::Size(498, 72);
            this->label30->TabIndex = 21;
            this->label30->Text = L"The Doctors\' Menu";
            // 
            // pictureBox27
            // 
            this->pictureBox27->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox27.Image")));
            this->pictureBox27->Location = System::Drawing::Point(-3, 0);
            this->pictureBox27->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox27->Name = L"pictureBox27";
            this->pictureBox27->Size = System::Drawing::Size(1352, 690);
            this->pictureBox27->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox27->TabIndex = 20;
            this->pictureBox27->TabStop = false;
            this->pictureBox27->Click += gcnew System::EventHandler(this, &MyForm::pictureBox27_Click);
            // 
            // button3
            // 
            this->button3->Cursor = System::Windows::Forms::Cursors::Hand;
            this->button3->Location = System::Drawing::Point(106, 504);
            this->button3->Name = L"button3";
            this->button3->Size = System::Drawing::Size(108, 35);
            this->button3->TabIndex = 47;
            this->button3->Text = L"End";
            this->button3->UseVisualStyleBackColor = true;
            this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
            // 
            // label19
            // 
            this->label19->AutoSize = true;
            this->label19->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 14));
            this->label19->ForeColor = System::Drawing::Color::White;
            this->label19->Location = System::Drawing::Point(121, 200);
            this->label19->Name = L"label19";
            this->label19->Size = System::Drawing::Size(0, 32);
            this->label19->TabIndex = 46;
            // 
            // button2
            // 
            this->button2->Location = System::Drawing::Point(106, 504);
            this->button2->Name = L"button2";
            this->button2->Size = System::Drawing::Size(108, 35);
            this->button2->TabIndex = 45;
            this->button2->Text = L"Next";
            this->button2->UseVisualStyleBackColor = true;
            this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click_1);
            // 
            // label18
            // 
            this->label18->AutoSize = true;
            this->label18->Location = System::Drawing::Point(129, 418);
            this->label18->Name = L"label18";
            this->label18->Size = System::Drawing::Size(0, 17);
            this->label18->TabIndex = 44;
            // 
            // textBox4
            // 
            this->textBox4->Location = System::Drawing::Point(127, 465);
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(196, 24);
            this->textBox4->TabIndex = 43;
            this->textBox4->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm::textBox4_KeyPress_1);
            // 
            // label17
            // 
            this->label17->AutoSize = true;
            this->label17->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20));
            this->label17->ForeColor = System::Drawing::Color::Snow;
            this->label17->Location = System::Drawing::Point(88, 93);
            this->label17->Name = L"label17";
            this->label17->Size = System::Drawing::Size(0, 46);
            this->label17->TabIndex = 42;
            // 
            // label16
            // 
            this->label16->AutoSize = true;
            this->label16->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label16->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label16->ForeColor = System::Drawing::Color::White;
            this->label16->Location = System::Drawing::Point(952, 592);
            this->label16->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label16->Name = L"label16";
            this->label16->Size = System::Drawing::Size(126, 28);
            this->label16->TabIndex = 41;
            this->label16->Text = L"Clear history";
            // 
            // pictureBox10
            // 
            this->pictureBox10->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox10.Image")));
            this->pictureBox10->Location = System::Drawing::Point(618, 271);
            this->pictureBox10->Name = L"pictureBox10";
            this->pictureBox10->Size = System::Drawing::Size(146, 142);
            this->pictureBox10->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
            this->pictureBox10->TabIndex = 40;
            this->pictureBox10->TabStop = false;
            // 
            // pictureBox11
            // 
            this->pictureBox11->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox11->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox11.Image")));
            this->pictureBox11->Location = System::Drawing::Point(875, 504);
            this->pictureBox11->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox11->Name = L"pictureBox11";
            this->pictureBox11->Size = System::Drawing::Size(69, 78);
            this->pictureBox11->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox11->TabIndex = 39;
            this->pictureBox11->TabStop = false;
            this->pictureBox11->Click += gcnew System::EventHandler(this, &MyForm::pictureBox11_Click);
            // 
            // pictureBox13
            // 
            this->pictureBox13->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox13->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox13.Image")));
            this->pictureBox13->Location = System::Drawing::Point(441, 516);
            this->pictureBox13->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox13->Name = L"pictureBox13";
            this->pictureBox13->Size = System::Drawing::Size(81, 78);
            this->pictureBox13->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox13->TabIndex = 37;
            this->pictureBox13->TabStop = false;
            this->pictureBox13->Click += gcnew System::EventHandler(this, &MyForm::pictureBox13_Click);
            // 
            // pictureBox14
            // 
            this->pictureBox14->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox14->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox14.Image")));
            this->pictureBox14->Location = System::Drawing::Point(441, 95);
            this->pictureBox14->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox14->Name = L"pictureBox14";
            this->pictureBox14->Size = System::Drawing::Size(70, 73);
            this->pictureBox14->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox14->TabIndex = 36;
            this->pictureBox14->TabStop = false;
            this->pictureBox14->Click += gcnew System::EventHandler(this, &MyForm::pictureBox14_Click);
            // 
            // label8
            // 
            this->label8->AutoSize = true;
            this->label8->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label8->ForeColor = System::Drawing::Color::White;
            this->label8->Location = System::Drawing::Point(946, 83);
            this->label8->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label8->Name = L"label8";
            this->label8->Size = System::Drawing::Size(125, 28);
            this->label8->TabIndex = 35;
            this->label8->Text = L"View history";
            // 
            // label9
            // 
            this->label9->AutoSize = true;
            this->label9->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label9->ForeColor = System::Drawing::Color::White;
            this->label9->Location = System::Drawing::Point(172, 592);
            this->label9->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label9->Name = L"label9";
            this->label9->Size = System::Drawing::Size(339, 28);
            this->label9->TabIndex = 34;
            this->label9->Text = L"View symptoms of a certain disease";
            // 
            // label12
            // 
            this->label12->AutoSize = true;
            this->label12->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label12->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label12->ForeColor = System::Drawing::Color::White;
            this->label12->Location = System::Drawing::Point(296, 94);
            this->label12->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label12->Name = L"label12";
            this->label12->Size = System::Drawing::Size(141, 28);
            this->label12->TabIndex = 33;
            this->label12->Text = L"Self-Diagnosis";
            // 
            // pictureBox15
            // 
            this->pictureBox15->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox15.Image")));
            this->pictureBox15->Location = System::Drawing::Point(441, 94);
            this->pictureBox15->Name = L"pictureBox15";
            this->pictureBox15->Size = System::Drawing::Size(503, 500);
            this->pictureBox15->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox15->TabIndex = 32;
            this->pictureBox15->TabStop = false;
            // 
            // pictureBox16
            // 
            this->pictureBox16->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox16->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox16.Image")));
            this->pictureBox16->Location = System::Drawing::Point(1207, 77);
            this->pictureBox16->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox16->Name = L"pictureBox16";
            this->pictureBox16->Size = System::Drawing::Size(50, 50);
            this->pictureBox16->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
            this->pictureBox16->TabIndex = 31;
            this->pictureBox16->TabStop = false;
            this->pictureBox16->Click += gcnew System::EventHandler(this, &MyForm::pictureBox16_Click);
            // 
            // pictureBox17
            // 
            this->pictureBox17->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox17->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox17.Image")));
            this->pictureBox17->Location = System::Drawing::Point(1207, 15);
            this->pictureBox17->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox17->Name = L"pictureBox17";
            this->pictureBox17->Size = System::Drawing::Size(50, 50);
            this->pictureBox17->SizeMode = System::Windows::Forms::PictureBoxSizeMode::AutoSize;
            this->pictureBox17->TabIndex = 30;
            this->pictureBox17->TabStop = false;
            this->pictureBox17->Click += gcnew System::EventHandler(this, &MyForm::pictureBox17_Click);
            // 
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label13->ForeColor = System::Drawing::Color::White;
            this->label13->Location = System::Drawing::Point(1152, 88);
            this->label13->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(51, 28);
            this->label13->TabIndex = 29;
            this->label13->Text = L"Quit";
            // 
            // label14
            // 
            this->label14->AutoSize = true;
            this->label14->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label14->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label14->ForeColor = System::Drawing::Color::White;
            this->label14->Location = System::Drawing::Point(1126, 25);
            this->label14->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label14->Name = L"label14";
            this->label14->Size = System::Drawing::Size(77, 28);
            this->label14->TabIndex = 28;
            this->label14->Text = L"Logout";
            // 
            // label15
            // 
            this->label15->AutoSize = true;
            this->label15->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->label15->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 32, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label15->ForeColor = System::Drawing::Color::White;
            this->label15->Location = System::Drawing::Point(50, 13);
            this->label15->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label15->Name = L"label15";
            this->label15->Size = System::Drawing::Size(501, 72);
            this->label15->TabIndex = 27;
            this->label15->Text = L"The Patient\'s Menu";
            // 
            // pictureBox18
            // 
            this->pictureBox18->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox18.Image")));
            this->pictureBox18->Location = System::Drawing::Point(0, 0);
            this->pictureBox18->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox18->Name = L"pictureBox18";
            this->pictureBox18->Size = System::Drawing::Size(1352, 690);
            this->pictureBox18->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox18->TabIndex = 26;
            this->pictureBox18->TabStop = false;
            // 
            // pictureBox1
            // 
            this->pictureBox1->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
            this->pictureBox1->Location = System::Drawing::Point(0, 0);
            this->pictureBox1->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox1->Name = L"pictureBox1";
            this->pictureBox1->Size = System::Drawing::Size(1923, 938);
            this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox1->TabIndex = 46;
            this->pictureBox1->TabStop = false;
            this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click_1);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->ClientSize = System::Drawing::Size(1699, 831);
            this->ControlBox = false;
            this->Controls->Add(this->panel3);
            this->Controls->Add(this->label11);
            this->Controls->Add(this->Register);
            this->Controls->Add(this->Sign_in);
            this->DoubleBuffered = true;
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"MyForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
            this->Text = L"Self-Diagnosis";
            this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MyForm::MyForm_FormClosing);
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(this, &MyForm::MyForm_FormClosed);
            this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox9))->EndInit();
            this->panel3->ResumeLayout(false);
            this->panel3->PerformLayout();
            this->panel4->ResumeLayout(false);
            this->panel4->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox16))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox17))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
		int counter_timer = 0;
	private: System::Void Sign_in_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Sign_in->Text == "Sign-in")
		{
			label10->Hide();
			pictureBox8->Hide();
			pictureBox9->Hide();
			Sign_in->Show();
			textBox1->Text = "";
			textBox2->Text = "";
			Register->Text = "Register.";
			Username->Text = "Username";
			Password->Text = "Password";
			Next->Hide();
			Password->Show();
			textBox2->Show();
			textBox3->Show();
			label2->Hide();
			timer1->Start();
			Sign_in->Text = "Sign-in.";
		}
        else{
			Register->Text = "Register";
			timer2->Start();
			Sign_in->Text = "Sign-in";
		}
	}
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (counter_timer < 10)
		{
			Form::Width += 40;
			counter_timer++;
		}
		else
		{
			timer1->Stop();
		}
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
		if (counter_timer > 0)
		{
			Form::Width -= 40;
			counter_timer--;
		}
		else
			timer2->Stop();
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
        getAllDoctors(allDoctors);
        getAllPatients(allPatients);
        getAllDiseases((&allDiseases));
        extract_Symptoms();
        GraphicsPath^ gp = gcnew GraphicsPath();
        gp->AddEllipse(pictureBox32->DisplayRectangle);
        pictureBox32->Region = gcnew System::Drawing::Region(gp);
        button9->Hide();
        timer3->Start();
        pictureBox1->SendToBack();
		Username->Parent = pictureBox1;
		Username->BackColor = BackColor.Transparent;
		Password->Parent = pictureBox1;
		Password->BackColor = BackColor.Transparent;
		pictureBox6->Parent = pictureBox1;
		pictureBox6->BackColor = BackColor.Transparent;
		pictureBox7->Parent = pictureBox1;
		pictureBox7->BackColor = BackColor.Transparent;
        label34->Parent = pictureBox1;
		label34->BackColor = BackColor.Transparent;
        label33->Parent = pictureBox1;
        label33->BackColor = BackColor.Transparent;
		label3->Parent = pictureBox1;
		label3->BackColor = BackColor.Transparent;
		label4->Parent = pictureBox1;
		label4->BackColor = BackColor.Transparent;
		label5->Parent = pictureBox1;
		label5->BackColor = BackColor.Transparent;
		label6->Parent = pictureBox1;
		label6->BackColor = BackColor.Transparent;
		label7->Parent = pictureBox1;
		label7->BackColor = BackColor.Transparent;
		label10->Parent = pictureBox1;
		label10->BackColor = BackColor.Transparent;
		pictureBox8->Parent = pictureBox1;
		pictureBox8->BackColor = BackColor.Transparent;
		pictureBox9->Parent = pictureBox1;
		pictureBox9->BackColor = BackColor.Transparent;
		pictureBox2->Parent = pictureBox1;
		pictureBox2->BackColor = BackColor.Transparent;
		label1->Parent = pictureBox1;
		label1->BackColor = BackColor.Transparent;
		pictureBox3->Parent = pictureBox1;
		pictureBox3->BackColor = BackColor.Transparent;
		pictureBox4->Parent = pictureBox1;
		pictureBox4->BackColor = BackColor.Transparent;
		pictureBox5->Parent = pictureBox1;
		pictureBox5->BackColor = BackColor.Transparent;
        label15->Parent = pictureBox18;
        label15->BackColor = BackColor.Transparent; 
        label12->Parent = pictureBox18;
        label12->BackColor = BackColor.Transparent;
        label8->Parent = pictureBox18;
        label8->BackColor = BackColor.Transparent;
        label9->Parent = pictureBox18;
        label9->BackColor = BackColor.Transparent;
        label16->Parent = pictureBox18;
        label16->BackColor = BackColor.Transparent;
        label14->Parent = pictureBox18;
        label14->BackColor = BackColor.Transparent; 
        label13->Parent = pictureBox18;
        label13->BackColor = BackColor.Transparent; 
        label19->Parent = pictureBox18;
        label19->BackColor = BackColor.Transparent;
        label17->Parent = pictureBox18;
        label17->BackColor = BackColor.Transparent;
        label20->Parent = pictureBox27;
        label20->BackColor = BackColor.Transparent;
        label21->Parent = pictureBox27;
        label21->BackColor = BackColor.Transparent;
        label22->Parent = pictureBox27;
        label22->BackColor = BackColor.Transparent;
        label23->Parent = pictureBox27;
        label23->BackColor = BackColor.Transparent;
        label24->Parent = pictureBox27;
        label24->BackColor = BackColor.Transparent;
        label25->Parent = pictureBox27;
        label25->BackColor = BackColor.Transparent;
        label26->Parent = pictureBox27;
        label26->BackColor = BackColor.Transparent;
        label27->Parent = pictureBox27;
        label27->BackColor = BackColor.Transparent;
        label29->Parent = pictureBox27;
        label29->BackColor = BackColor.Transparent;
        label28->Parent = pictureBox27;
        label28->BackColor = BackColor.Transparent;
        label30->Parent = pictureBox27;
        label30->BackColor = BackColor.Transparent;
        label31->Parent = pictureBox27;
        label31->BackColor = BackColor.Transparent;
        pictureBox10->Parent = pictureBox18;
        pictureBox10->BackColor = BackColor.Transparent;
        pictureBox11->Parent = pictureBox18;
        pictureBox11->BackColor = BackColor.Transparent;
        pictureBox12->Parent = pictureBox18;
        pictureBox12->BackColor = BackColor.Transparent;
        pictureBox13->Parent = pictureBox18;
        pictureBox13->BackColor = BackColor.Transparent;
        pictureBox14->Parent = pictureBox18;
        pictureBox14->BackColor = BackColor.Transparent;
        pictureBox15->Parent = pictureBox18;
        pictureBox15->BackColor = BackColor.Transparent;
        pictureBox16->Parent = pictureBox18;
        pictureBox16->BackColor = BackColor.Transparent;
        pictureBox17->Parent = pictureBox18;
        pictureBox17->BackColor = BackColor.Transparent;
        pictureBox19->Parent = pictureBox27;
        pictureBox19->BackColor = BackColor.Transparent;
        pictureBox20->Parent = pictureBox27;
        pictureBox20->BackColor = BackColor.Transparent;
        pictureBox21->Parent = pictureBox27;
        pictureBox21->BackColor = BackColor.Transparent;
        pictureBox22->Parent = pictureBox27;
        pictureBox22->BackColor = BackColor.Transparent;
        pictureBox23->Parent = pictureBox27;
        pictureBox23->BackColor = BackColor.Transparent;
        pictureBox24->Parent = pictureBox27;
        pictureBox24->BackColor = BackColor.Transparent;
        pictureBox25->Parent = pictureBox27;
        pictureBox25->BackColor = BackColor.Transparent;
        pictureBox26->Parent = pictureBox27;
        pictureBox26->BackColor = BackColor.Transparent;
        pictureBox30->Parent = pictureBox27;
        pictureBox30->BackColor = BackColor.Transparent;
        pictureBox29->Parent = pictureBox27;
        pictureBox29->BackColor = BackColor.Transparent;
        pictureBox28->Parent = pictureBox27;
        pictureBox28->BackColor = BackColor.Transparent;


        textBox3->Hide();
        label29->Text = "lol";
        label18->Hide();
        label17->Hide();
        textBox4->Hide();
        button2->Hide();
        panel4->Hide();
        panel5->Hide();
        label19->Hide();
        button3->Hide();
        label29->Hide();
        label28->Hide();
        textBox5->Hide();
        button4->Hide();
        button6->Hide();
        label32->Hide();
        label31->Hide();
        textBox6->Hide();
        Back_P->Hide();
        button7->Hide();
        label33->Hide();
        button5->Hide();
        pictureBox31->Hide();
        button8->Hide();
        label34->Hide();
	}
	private: System::Void Quit_Click(System::Object^ sender, System::EventArgs^ e) {
        writeAllPatients(allPatients);
        writeAllDiseases(allDiseases);
        writeAllDoctors(allDoctors);
		this->Close();
	}
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
        if (button1->Text == "Sign-in") {
            textBox3->Hide();
            if (textBox1->Text != "" && textBox2->Text != "") {
                label2->Hide();
                string username;
                string password;
                MarshalString(textBox1->Text, username);
                MarshalString(textBox2->Text, password);
                if (doctorLogin(allDoctors, username, password, CurrentDoctor, index_allDoctors)) {
                    panel4->Show();
                    panel5->Show();
                    label2->Hide();
                    PrintDoctorMenu();
                    Form::Width -= 200;
                    Form::Height -= 150;
                    
                    label6->ForeColor = Color::FromArgb(255, 255, 255);
                    label5->ForeColor = Color::FromArgb(255, 255, 255);
                }
                else if (patientLogin(allPatients, username, password, CurrentPatient, index_allPatients)) {
                    panel4->Show();
                    panel5->Hide();
                    label2->Hide();
                    printPatientMenu();
                    Form::Width -= 200;
                    Form::Height -= 150;
                }
                else {
                    label2->Text = "Incorrect Username or Password.";
                    label2->Show();
                }
            }
            else {
                label2->Text = "Incorrect Username or Password.";
                textBox1->Text = "";
                textBox2->Text = "";
                label2->Show();
            }
        }
       
	}
	private: System::Void Register_Click(System::Object^ sender, System::EventArgs^ e) {

		if (Register->Text == "Register")

		{
            textBox3->Text = "";
			label10->Hide();
			pictureBox6->Show();
			pictureBox7->Show();
			pictureBox8->Hide();
			pictureBox9->Hide();
		}
		else
		{
			Sign_in->Text = "Sign-in";
			timer2->Start();
			Register->Text = "Register";
		}
		//Doc_name=label->Text;
	}
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {
        if (Next->Text == "NEXT") {
            if (Password->Text == "E-Mail") {
                string from, pass, MessageBody;
                srand(time(0));
                randomCode = to_string((rand() % 10000000) + 1000000);
                Code = gcnew String(randomCode.c_str());
                MailMessage^ message = gcnew MailMessage();
                from = "selfdiagnosissupp@gmail.com";
                pass = "eomootfkfmpefvut";
                MessageBody = "Your Reset Code is " + randomCode + " Matensash el password el mara el gaya ya 5anzeer";
                String^ From = gcnew String(from.c_str());
                String^ MB = gcnew String(MessageBody.c_str());
                String^ To = gcnew String(to.c_str());
                String^ Pass = gcnew String(pass.c_str());
                message->From = gcnew MailAddress(From);
                message->Body = MB;
                message->Subject = "Password Reseting Code";
                if (Sign_in->Text == "Sign-in.") {
                    if (textBox1->Text != "") {
                        string user;
                        MarshalString(textBox1->Text, user);
                        for (int i = 0; i < index_allDoctors; i++) {
                            if (user == allDoctors[i].account.username) {
                                if (textBox2->Text != "") {
                                    string em;
                                    MarshalString(textBox2->Text, em);
                                    if (allDoctors[i].account.email == em) {
                                        To = textBox2->Text;
                                        SmtpClient^ smtp = gcnew SmtpClient("smtp.gmail.com");
                                        smtp->EnableSsl = true;
                                        message->To->Add(To);
                                        smtp->Port = 587;
                                        smtp->DeliveryMethod = SmtpDeliveryMethod::Network;
                                        smtp->Credentials = gcnew NetworkCredential(From, Pass);
                                        try {
                                            smtp->Send(message);
                                            message->To->Clear();
                                            MyForm2^ sc = gcnew MyForm2(randomCode, allDoctors[i].account.username, allDoctors[i].account.password);
                                            string Pass1 = allDoctors[i].account.password;
                                            this->Hide();
                                            sc->ShowDialog();
                                            this->Show();
                                            string PASS;
                                            MarshalString(sc->GetPass(), PASS);
                                            allDoctors[i].account.password = PASS;
                                            if (Pass1 != PASS && PASS != "") {
                                                String^ u = gcnew String(allDoctors[i].account.username.c_str());
                                                String^ p = gcnew String(allDoctors[i].account.password.c_str());
                                                button5->PerformClick();
                                                textBox1->Text = u;
                                                textBox2->Text = p;
                                                button1->PerformClick();
                                            }
                                            textBox1->Text = "";
                                            textBox2->Text = "";

                                            label2->Hide();

                                        }
                                        catch (exception ex) {
                                            label2->Show();
                                            label2->Text = "error";
                                        }

                                    }
                                    else {
                                        label2->Show();
                                        label2->Text = "Username or E-Mail are incorrect";
                                    }
                                }
                                else {
                                    label2->Show();
                                    label2->Text = "Please enter an E-Mail";
                                }
                                break;
                            }

                        }
                        for (int i = 0; i < index_allPatients; i++) {
                            if (user == allPatients[i].account.username) {
                                if (textBox2->Text != "") {
                                    string em;
                                    MarshalString(textBox2->Text, em);
                                    if (allPatients[i].account.email == em) {
                                        To = textBox2->Text;
                                        SmtpClient^ smtp = gcnew SmtpClient("smtp.gmail.com");
                                        smtp->EnableSsl = true;
                                        message->To->Add(To);
                                        smtp->Port = 587;
                                        smtp->DeliveryMethod = SmtpDeliveryMethod::Network;
                                        smtp->Credentials = gcnew NetworkCredential(From, Pass);
                                        try {
                                            smtp->Send(message);
                                            message->To->Clear();
                                            MyForm2^ sc = gcnew MyForm2(randomCode, allPatients[i].account.username,allPatients[i].account.password);
                                            string Pass1 = allPatients[i].account.password;
                                            this->Hide();
                                            sc->ShowDialog();
                                            this->Show();
                                            string PASS;
                                            MarshalString(sc->GetPass(), PASS);
                                            allPatients[i].account.password = PASS;
                                            label2->Hide();
                                            if (Pass1 != PASS && PASS != "") {
                                                String^ u = gcnew String(allPatients[i].account.username.c_str());
                                                String^ p = gcnew String(allPatients[i].account.password.c_str());
                                                button5->PerformClick();
                                                textBox1->Text = u;
                                                textBox2->Text = p;
                                                button1->PerformClick();
                                            }
                                            textBox1->Text = "";
                                            textBox2->Text = "";

                                        }
                                        catch (exception ex) {
                                            label2->Show();
                                            label2->Text = "error";
                                        }
                                    }
                                    else {
                                        label2->Show();
                                        label2->Text = "Username or E-Mail are incorrect";
                                    }
                                }
                                else {
                                    label2->Show();
                                    label2->Text = "Please enter an E-Mail";
                                }
                                break;
                            }
                        }

                    }
                }
            }
            else if (label11->Text == "p") {
                bool test_name = true;
                if (textBox1->Text != "") {
                    if (Username->Text == "Please enter your Full Name.") {
                        MarshalString(textBox1->Text, pat_name);
                        if (pat_name.size() >= 3) {

                            label2->Text = "Enter a name with more than three letters";
                            label2->Show();

                            for (int i = 0; i < pat_name.size(); i++) {
                                char c = pat_name[i];
                                /*Here it checks if the string has number or not*/
                                if (islower(c) || isupper(c) || isspace(c)) {
                                    test_name = true;
                                    continue;
                                }
                                else {
                                    test_name = false;
                                    break;
                                }
                            }
                        }
                        else {
                            test_name = false;
                        }
                        if (test_name == false) {
                            label2->Text = "Enter a Full Name with 3 or more alphabets and without numbers.";
                            label2->Show();
                        }
                        else {
                            Username->Text = "Username";
                            textBox1->Text = "";
                            label2->Hide();

                        }
                        label10->Hide();

                    }
                }
                if (Username->Text == "Username") {
                    test_name = false;
                    MarshalString(textBox1->Text, pat_username);
                    if (pat_username.size() >= 3) {
                        for (int i = 0; i < pat_username.size(); i++) {
                            char c = pat_username[i];
                            if (isalnum(c)) {
                                test_name = true;
                                continue;
                            }
                            else {
                                label2->Text = "username cannot have symbols";
                                label2->Show();
                                test_name = false;
                                break;
                            }

                        }

                        bool check_username;
                        if (textBox1->Text != "") {
                            if (test_name) {
                                bool check_username = check_database(pat_username);
                                if (check_username == false) {
                                    label2->Text = "this username is already taken";
                                    label2->Show();
                                }
                                else {
                                    panel2->Show();
                                    textBox1->Text = "";
                                    Username->Text = "Password";
                                    textBox2->Text = "";
                                    textBox2->Show();
                                    Password->Text = "Renter Password";
                                    Password->Show();



                                }
                            }
                        }

                    }
                    else if (pat_username.size() > 0) {
                        test_name = false;
                        label2->Text = "Username must contain 3 or more characters";
                        label2->Show();
                    }
                }
                if (Username->Text == "Password") {
                    label2->Hide();
                    MarshalString(textBox1->Text, pat_password);
                    if ((textBox1->Text == textBox2->Text)) {
                        if (textBox1->Text != "" && textBox2->Text != "") {
                            string org2 = "";
                            for (int i = 0; i < pat_password.size(); i++) {
                                org2 += char(tolower(pat_password[i]));
                            }
                            string org1 = "";
                            for (int i = 0; i < pat_username.size(); i++) {
                                org1 += char(tolower(pat_username[i]));
                            }
                            if (org1 != org2) {
                                Username->Text = "Please select Age";
                                textBox2->Hide();
                                panel2->Hide();
                                textBox1->Hide();
                                textBox3->Show();
                                Password->Hide();
                            }

                            else {
                                label2->Text = "Username and Password cannot be the same";
                                label2->Show();
                            }
                        }
                    }
                    else {

                        label2->Text = "Passwords Do not match";
                        label2->Show();

                    }

                }
                if (Username->Text == "Please select Age") {
                    textBox1->Text = "";
                    label2->Hide();
                    Password->Hide();
                    textBox2->Hide();
                    textBox1->Hide();
                    textBox3->Show();
                    if (textBox3->Text != "") {
                        int Age = System::Convert::ToInt32(textBox3->Text);
                        if (Age > 120 || Age < 12) {
                            label2->Text = "Please enter a suitable Age";
                            label2->Show();
                            textBox3->Text = "";
                        }
                        else {
                            MarshalString(textBox3->Text, pat_age);
                            label2->Hide();
                            textBox3->Text = "";
                            textBox3->Hide();
                            textBox1->Show();
                            Username->Text = "E-Mail";
                            textBox1->Text = "";

                        }
                    }
                }
                if (Username->Text == "E-Mail") {

                    bool check_mail = false;
                    if (textBox1->Text != "") {
                        MarshalString(textBox1->Text, mail);
                        for (int i = 0; i < mail.size(); i++) {
                            if (mail[i] == '@') {
                                check_mail = true;
                                break;
                            }
                        }
                        if (check_mail) {
                            if (check_database_email(mail)) {
                                MyCamera->Start(0);
                                pictureBox31->Show();
                                button9->Show();
                                label34->Show();
                                button8->Show();
                                Next->Text = "Capture";
                                Username->Text = "Cam";

                            }  
                            else {
                                label2->Show();
                                label2->Text = "This Email  is used by an another account";
                            }
                        }
                        else {
                            label2->Show();
                            label2->Text = "Invalid Email";
                        }
                    }
                }
            }
            else if (label11->Text == "d") {

                bool test_name = true;

                if (Username->Text == "Please enter your Full Name.") {
                    MarshalString(textBox1->Text, doc_name);
                    if (doc_name.size() >= 3) {

                        label2->Text = "Enter a name with more than three letters";
                        label2->Show();

                        for (int i = 0; i < doc_name.size(); i++) {
                            char c = doc_name[i];
                            /*Here it checks if the string has number or not*/
                            if (islower(c) || isupper(c) || isspace(c)) {
                                test_name = true;
                                continue;
                            }
                            else {
                                test_name = false;
                                break;
                            }
                        }
                    }
                    else {
                        label2->Show();
                        test_name = false;
                    }
                    if (test_name == false) {
                        label2->Text = "Enter a Full Name with 3 or more alphabets and without numbers.";
                        label2->Show();
                    }
                    else {
                        Username->Text = "Username";
                        textBox1->Text = "";
                        label2->Hide();

                    }
                    label10->Hide();
                }
                if (Username->Text == "Username") {

                    test_name = false;
                    MarshalString(textBox1->Text, doc_username);
                    if (doc_username.size() >= 3) {
                        for (int i = 0; i < doc_username.size(); i++) {
                            char c = doc_username[i];
                            if (isalnum(c)) {
                                test_name = true;
                                continue;
                            }
                            else {
                                label2->Text = "username cannot have symbols";
                                label2->Show();
                                test_name = false;
                                break;
                            }

                        }

                        bool check_username;
                        if (test_name) {
                            bool check_username = check_database(doc_username);
                            if (check_username == false) {
                                label2->Text = "this username is already taken";
                                label2->Show();
                            }
                            else {
                                label2->Hide();
                                panel2->Show();
                                textBox1->Text = "";
                                Username->Text = "Password";
                                textBox2->Text = "";
                                textBox2->Show();
                                Password->Text = "Renter Password";
                                Password->Show();


                            }
                        }

                    }
                    else if (doc_username.size() > 0) {
                        test_name = false;
                        label2->Text = "Username must contain 3 or more characters";
                        label2->Show();
                    }
                }

                if (Username->Text == "Password") {
                    label2->Hide();
                    if (textBox1->Text != "") {
                        MarshalString(textBox1->Text, doc_password);
                        if ((textBox1->Text == textBox2->Text)) {
                            if (textBox1->Text != "" && textBox2->Text != "") {
                                string org2 = "";
                                for (int i = 0; i < doc_password.size(); i++) {
                                    org2 += char(tolower(doc_password[i]));
                                }
                                string org1 = "";
                                for (int i = 0; i < doc_username.size(); i++) {
                                    org1 += char(tolower(doc_username[i]));
                                }

                                if (org1 != org2) {
                                    Username->Text = "Mobile Phone Number";
                                    textBox2->Hide();
                                    panel2->Hide();
                                    textBox1->Hide();
                                    textBox3->Show();
                                    textBox3->Text = "";
                                    Password->Hide();
                                }

                                else {
                                    label2->Text = "Username and Password cannot be the same";
                                    label2->Show();
                                }
                            }
                        }
                        else {

                            label2->Text = "Passwords Do not match";
                            label2->Show();

                        }

                    }
                }

                if (Username->Text == "Mobile Phone Number") {

                    if (textBox3->Text != "") {
                        double mphone = System::Convert::ToDouble(textBox3->Text);
                        textBox3->Text = "";
                        double cphone = mphone;
                        bool vphone = true;
                        int lengthCount = 1;
                        for (; cphone > 0.9; cphone /= 10, lengthCount++);//Here we count the entered numbers
                        if (lengthCount != 11) {
                            vphone = false;
                            label2->Text = "Phone numbers are 11 numbers";
                            label2->Show();

                        }
                        int check[11];
                        for (int i = lengthCount - 1; i >= 0; i--) {
                            check[i] = (int)mphone % 10;
                            mphone /= 10;
                        }
                        if (check[2] != 1 && check[2] != 2 && check[2] != 0 && check[2] != 5) {
                            label2->Text = "Invalid phone number";
                            label2->Show();
                            vphone = false;
                        }
                        if (vphone) {
                            doctor_phone = "";
                            for (int i = 0; i < lengthCount; i++) {
                                doctor_phone += to_string(check[i]);
                            }
                            if (check_phone(doctor_phone)) {
                                Username->Text = "E-Mail";
                                textBox3->Text = "";
                                textBox3->Hide();
                                textBox1->Show();
                                textBox1->Text = "";
                                label2->Hide();
                            }
                            else {
                                label2->Text = "phone number is already taken";
                                label2->Show();
                                textBox3->Text = "";
                            }

                        }
                    }
                }

                if (Username->Text == "E-Mail") {
                    bool check_mail = false;
                    if (textBox1->Text != "") {
                        MarshalString(textBox1->Text, mail);
                        for (int i = 0; i < mail.size(); i++) {
                            if (mail[i] == '@') {
                                check_mail = true;
                                break;
                            }
                        }
                        if (check_mail) {
                            if (check_database_email(mail)) {
                                MyCamera->Start(0);
                                label34->Show();
                                button9->Show();
                                pictureBox31->Show();
                                button8->Show();
                                Username->Text = "Cam";
                                Next->Text = "Capture";
                               
                            }
                            else {
                                label2->Show();
                                label2->Text = "This Email  is used by an another account";
                            }
                        }
                        else {
                            label2->Show();
                            label2->Text = "Invalid Email";
                        }
                    }
                }


            }
        }
        else if (Next->Text == "Capture") {
            MyCamera->Stop();
            if (label11->Text == "d") {
                button8->Text = "End";
            }
            else {
                button8->Text = "Next";
            }
            Next->Text = "Retake";
        }
        else if (Next->Text == "Retake") {
        MyCamera->Start(0);
        Next->Text = "Capture";
        button8->Text = "No Profile Picture";
        }
        else if (Next->Text == "Take a Picture") {
        button8->Text = "No Profile Picture";
        MyCamera->Start(0);
}
	
}


private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void panel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void textBox3_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char ch = e->KeyChar;
	if (!isdigit(ch) && ch != 8)
	{
		e->Handled = true;
	}
}
private: System::Void pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	if (Sign_in->Text == "Sign-in")
	{
        label5->ForeColor = Color::FromArgb(0, 0, 153);
        label6->ForeColor = Color::FromArgb(255, 255, 255);
        label34->Hide();
        pictureBox31->Hide();
        button8->Hide();
        Next->Text = "NEXT";
        button1->Text="Sign-in";
        this->textBox2->PasswordChar = '*';
        button5->Hide();
        label33->Show();
        textBox1->Show();
        textBox3->Hide();
		label10->Hide();
		label3->Hide();
		label4->Hide();
		button1->Show();
		Username->Show();
		panel1->Show();
		panel2->Show();
		pictureBox6->Hide();
		pictureBox7->Hide();
		pictureBox8->Hide();
		pictureBox9->Hide();
		Sign_in->Show();
		textBox1->Text = "";
		textBox2->Text = "";
		Register->Text = "Register.";
		Username->Text = "Username";
		Password->Text = "Password";
		Next->Hide();
		Password->Show();
		textBox2->Show();
		textBox3->Show();
		label2->Hide();
		timer1->Start();
		Sign_in->Text = "Sign-in.";
	}
	else

	{
		Register->Text = "Register";
		timer2->Start();
		Sign_in->Text = "Sign-in";

	}
}

private: System::Void pictureBox4_Click(System::Object^ sender, System::EventArgs^ e) {

	if (Register->Text == "Register")

	{
        
        this->textBox2->PasswordChar = NULL;
        label34->Hide();
        pictureBox31->Hide();
        button8->Hide();
        Next->Text = "NEXT";
        Password->Text = "";
		label3->Text="DOCTOR";
		label4->Text="PATIENT";
        button5->Location = Drawing::Point(1180, 479);
        button5->Hide();
		label3->Show();
		label4->Show();
		label10->Hide();
        label33->Hide();
		pictureBox6->Show();
		pictureBox7->Show();

		pictureBox8->Hide();
		pictureBox9->Hide();

		textBox1->Text = "";
		textBox2->Text = "";
		textBox1->Hide();
		textBox3->Hide();
		panel1->Hide();
		panel2->Hide();
		Next->Hide();
		Sign_in->Text = "Sign-in.";
		label2->Hide();
		timer1->Start();
		Register->Text = "Register.";
		Password->Hide();
		textBox2->Hide();
		Username->Text = "Please enter your Full Name.";
		Username->Hide();
		button1->Hide();
	}
	else
	{
		Sign_in->Text = "Sign-in";
		timer2->Start();
		Register->Text = "Register";
	}
}
private: System::Void pictureBox5_Click(System::Object^ sender, System::EventArgs^ e) {
    
    System::Windows::Forms::SendKeys::Send("%");
    /*if (MessageBox::Show("Are you sure you want to quit?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
        writeAllPatients(allPatients);
        writeAllDiseases(allDiseases);
        writeAllDoctors(allDoctors);*/
        this->Close();
    //}
}
private: System::Void radioButton1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void z(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
}
private: System::Void axWindowsMediaPlayer1_Enter(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox6_Click(System::Object^ sender, System::EventArgs^ e) {
	label11->Text = "d";
    button5->Show();
	label3->Hide();
	label4->Hide();
	pictureBox6->Hide();
	pictureBox7->Hide();
	textBox1->Text = "";
	textBox2->Text = "";
	textBox1->Show();
	textBox3->Hide();
	panel1->Show();
	panel2->Hide();
	Next->Show();
	Sign_in->Text = "Sign-in.";
	label2->Hide();
	timer1->Start();
	Register->Text = "Register.";
	Password->Hide();
	textBox2->Hide();
	Username->Text = "Please enter your Full Name.";
	Username->Show();
	button1->Hide();
}
private: System::Void pictureBox7_Click(System::Object^ sender, System::EventArgs^ e) {
	label11->Text = "p";
    button5->Show();
	label3->Hide();
	label4->Hide();
	pictureBox6->Hide();
	pictureBox7->Hide();
	textBox1->Text = "";
	textBox2->Text = "";
	textBox1->Show();
	textBox3->Hide();
	panel1->Show();
	panel2->Hide();
	Next->Show();
	Sign_in->Text = "Sign-in.";
	label2->Hide();
	timer1->Start();
	Register->Text = "Register.";
	Password->Hide();
	textBox2->Hide();
	Username->Text = "Please enter your Full Name.";
	Username->Show();
	button1->Hide();
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox2_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox9_Click(System::Object^ sender, System::EventArgs^ e) {
    Pat_gender = "M";
    if (button8->Text != "No Profile Picture") {
        
        string wow = "PICs\\Patients\\" + pat_username + ".jpg";
        String^ str2 = gcnew String(wow.c_str());
        if (System::IO::File::Exists(str2)) {
            System::IO::File::Delete(str2);
        }
        pictureBox31->Image->Save(str2, ImageFormat::Jpeg);
    }
    Patient New_Patient = { pat_name, {pat_username, pat_password,mail}, Pat_gender[0], stoi(pat_age) };
    allPatients[index_allPatients] = New_Patient;
    CurrentPatient = &allPatients[index_allPatients];
    index_allPatients++;
    panel4->Show();
    panel5->Hide();
    Form::Width -= 200;
    Form::Height -= 150;
    printPatientMenu();
   
}
private: System::Void pictureBox8_Click(System::Object^ sender, System::EventArgs^ e) {
    if (button8->Text != "No Profile Picture") {

        string wow = "PICs\\Patients\\" + pat_username + ".jpg";
        String^ str2 = gcnew String(wow.c_str());
        if (System::IO::File::Exists(str2)) {
            System::IO::File::Delete(str2);
        }
        pictureBox31->Image->Save(str2, ImageFormat::Jpeg);
    }
    Pat_gender = "F";
    Patient New_Patient = { pat_name, {pat_username, pat_password,mail}, Pat_gender[0], stoi(pat_age) };
    allPatients[index_allPatients] = New_Patient;
    CurrentPatient = &allPatients[index_allPatients];
    index_allPatients++;
    panel4->Show();
    panel5->Hide();
    Form::Width -= 200;
    Form::Height -= 150;
    printPatientMenu();
}

    int counter_timer1=0;
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
    if (counter_timer1 > 10) {
      /*  pictureBox31->Hide();*/
    }
    else {
        counter_timer1++;
    }
}

private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void pictureBox16_Click(System::Object^ sender, System::EventArgs^ e) {
    System::Windows::Forms::SendKeys::Send("%");
   /* if (MessageBox::Show("Are you sure you want to quit?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
        writeAllPatients(allPatients);
        writeAllDiseases(allDiseases);
        writeAllDoctors(allDoctors);
    }*/
        this->Close();
}
private: System::Void pictureBox17_Click(System::Object^ sender, System::EventArgs^ e) {
    if (MessageBox::Show("Are you sure you want to Logout?", "Logout?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
        logout_back();
    }
}
private: System::Void pictureBox14_Click(System::Object^ sender, System::EventArgs^ e) {
    label12->Hide();
    label8->Hide();
    label9->Hide();
    label16->Hide();
    pictureBox10->Hide();
    pictureBox11->Hide();
    pictureBox12->Hide();
    pictureBox13->Hide();
    pictureBox14->Hide();
    pictureBox15->Hide();
    textBox4->Show();
    button2->Text = "Next";
    button2->Show();
    Back_P->Show();
    view_all_Symptoms();
    symptoms_patient_feeling.clear();
   
}
private: System::Void pictureBox12_Click(System::Object^ sender, System::EventArgs^ e) {
   


}
private: System::Void pictureBox13_Click(System::Object^ sender, System::EventArgs^ e) {
   
    Back_P->Show();
    label12->Hide();
    label8->Hide();
    label9->Hide();
    label16->Hide();
    pictureBox10->Hide();
    pictureBox11->Hide();
    pictureBox12->Hide();
    pictureBox13->Hide();
    pictureBox14->Hide();
    pictureBox15->Hide();
    display_Symptoms_for_Disease();
}
private: System::Void pictureBox11_Click(System::Object^ sender, System::EventArgs^ e) {

    if ((*CurrentPatient).Disease_History.size() == 0) {
        MessageBox::Show("You Do not have a History to delete.", "Delete History?", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    else {
       
         if (MessageBox::Show("Are you sure you want to delete your history?", "Delete History?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
        (*CurrentPatient).Disease_History.clear();
                  }
    }
}
private: System::Void textBox4_KeyPress_1(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    char ch = e->KeyChar;
    if (!isdigit(ch) && ch != 8)
    {
        e->Handled = true;
    }
}
bool check1 = true;
private: System::Void button2_Click_1(System::Object^ sender, System::EventArgs^ e) {
    string x = "";
    bool check = true;
   
     if (textBox4->Text != ""&&check1==true) {
        MarshalString(textBox4->Text, x);
        if (x == "0" && symptoms_patient_feeling.size() == 0) {
            label12->Show();
            label8->Show();
            label9->Show();
            label16->Show();
            pictureBox10->Show();
            pictureBox11->Show();
            pictureBox12->Show();
            pictureBox13->Show();
            pictureBox14->Show();
            pictureBox15->Show();
            label18->Hide();
            button2->Hide();
            textBox4->Hide();
            textBox4->Text = "";
            label17->Hide();
            label19->Hide();
            check = false;
        }
        else if (x == "0") {

            textBox4->Text = "";
            textBox4->Hide();
            button2->Hide();
            label19->Hide();
            label18->Hide();
            check = false;
            check1 = false;
            index_self = 1;
            index_related = 1;
            Back_P->Hide();
            selfdiagnosis();
            
            label17->Hide();
            button2->Text = "Next";
            button2->Show();
        }
        else if (stoi(x) > allSymptoms.size()) {
            label18->Text = "Invalid entry";
            label18->Show();
            check = false;

        }
        if (check) {
            bool check_duplicate = true;
            for (int i = 0; i < symptoms_patient_feeling.size(); i++) {
                if (symptoms_patient_feeling[i] == x) {
                    check_duplicate = false;
                    break;
                }
            }

            if (check_duplicate) {
                symptoms_patient_feeling.push_back(x);
                label18->Hide();
                textBox4->Text = "";
            }


            else
            {
                label18->Text = "You entered this number before. Please enter another number";
                label18->Show();
            }
        }

    }
    else {
        label18->Text = "Enter 0 when you are done";
        label18->Show();
    }
     if (button2->Text == "End") {
         label12->Show();
         label8->Show();
         label9->Show();
         label16->Show();
         pictureBox10->Show();
         pictureBox11->Show();
         pictureBox12->Show();
         pictureBox13->Show();
         pictureBox14->Show();
         pictureBox15->Show();
         label18->Hide();
         button2->Hide();
         textBox4->Hide();
         textBox4->Text = "";
         label17->Hide();
         label19->Hide();
     }
     else if (button2->Text == "Next" && check1 == false) {
         label18->Hide();
         if (index_self <= Disease_Diagnosed.size()) {
             String^ index = gcnew String(to_string(index_self).c_str());
             String^ str2 = gcnew String(Disease_Diagnosed[index_self-1].name.c_str());
             string per = to_string(percentage_of_diagnosed_Disease[index_self-1] * 100);
             per = per.substr(0, 4);
             String^ percentage = gcnew String(per.c_str());
             String^ info = gcnew String(Disease_Diagnosed[index_self-1].info.c_str());
             label19->Text = String::Format("You are {0}% diagnosed with: {1}\nGeneral Information:\n{2}\nYou may feel symptoms like:", percentage, str2, info);
             for (int j = 1; j <= Disease_Diagnosed[index_self-1].symps.size(); j++) {
                 string symp = Disease_Diagnosed[index_self-1].symps[j - 1];
                 String^ symptom = gcnew String(symp.c_str());
                 String^ index1 = gcnew String(to_string(j).c_str());
                 if(j==1||j%5==0)
                     label19->Text += String::Format("\n{0}-{1}", index1, symptom);
                 else
                     label19->Text += String::Format("     {0}-{1}", index1, symptom);
             }
             String^ name = gcnew String(Disease_Diagnosed[index_self-1].doc_name.c_str());
             String^ phone = gcnew String(Disease_Diagnosed[index_self-1].doc_phone.c_str());
             label19->Text += String::Format("\nYou can contact Dr.{0} to make an appointment\nPhone Number: {1}", name, phone);
             label19->Show();
             if (index_self == Disease_Diagnosed.size()) {
                 button2->Text = "End";
                 check1 = true;
             }
             string from, pass, MessageBody;
             MailMessage^ message = gcnew MailMessage();
             from = "selfdiagnosissupp@gmail.com";
             pass = "eomootfkfmpefvut";
             MessageBody = ( * CurrentPatient).patient_name+" has been diagnosed with "+Disease_Diagnosed[index_self-1].name+".\nfor contact: "+(*CurrentPatient).account.email;
             String^ From = gcnew String(from.c_str());
             String^ MB = gcnew String(MessageBody.c_str());
             String^ To;
             String^ Pass = gcnew String(pass.c_str());
             message->From = gcnew MailAddress(From);
             message->Body = MB;
             message->Subject = "A New Patient has been diagnosed with your disease"; 
             for (int i = 0; i < index_allDoctors; i++) {
                 if (Disease_Diagnosed[index_self - 1].doc_name == allDoctors[i].doc_name) {
                     To = gcnew String(allDoctors[i].account.email.c_str());
                 }
             }
             SmtpClient^ smtp = gcnew SmtpClient("smtp.gmail.com");
             smtp->EnableSsl = true;
             message->To->Add(To);
             smtp->Port = 587;
             smtp->DeliveryMethod = SmtpDeliveryMethod::Network;
             smtp->Credentials = gcnew NetworkCredential(From, Pass);
             smtp->Send(message);
             message->To->Clear();

             index_self++;

         }
         else if (Related_Diseases.size() > 0) {
             float max_value = -1;
             int max_index;
             vector<int> index_max;

             label17->Text="You are not diagnosed with any Diseases,\nHere is the closest disease related to your symptoms:\n";
             label17->Show();
             for (int i = 0; i < percentage_of_related_Disease.size(); i++) {
                 if (percentage_of_related_Disease[i] > max_value) {
                     max_value = percentage_of_related_Disease[i];
                     max_index = i;
                 }
             }
             index_max.push_back(max_index);
             max_index++;
             for (max_index; max_index < percentage_of_related_Disease.size(); max_index++) {
                 if (percentage_of_related_Disease[max_index] == max_value) {
                     index_max.push_back(max_index);
                 }
             }
             label19->Text = "";
  
             if (index_related <= index_max.size()) {
                 String^ index = gcnew String(to_string(index_related).c_str());
                 String^ str2 = gcnew String(Related_Diseases[index_related-1].name.c_str());
                 string per = to_string(percentage_of_related_Disease[index_related-1] * 100);
                 per = per.substr(0, 4);
                 String^ percentage = gcnew String(per.c_str());
                 String^ info = gcnew String(Related_Diseases[index_related - 1].info.c_str());
                 label19->Text += String::Format("{0}-{1} with {2}%\nGeneral Information:\n{3}\nYou may feel symptoms like", index, str2,percentage,info);
                 for (int j = 1; j <= Related_Diseases[index_related - 1].symps.size(); j++) {
                     string symp = Related_Diseases[index_related - 1].symps[j - 1];
                     String^ symptom = gcnew String(symp.c_str());
                     String^ index1 = gcnew String(to_string(j).c_str());
                     if (j == 1 || j % 5 == 0)
                         label19->Text += String::Format("\n{0}-{1}", index1, symptom);
                     else
                         label19->Text += String::Format("     {0}-{1}", index1, symptom);
                 }
                 String^ name = gcnew String(Related_Diseases[index_related - 1].doc_name.c_str());
                 String^ phone = gcnew String(Related_Diseases[index_related - 1].doc_phone.c_str());
                 label19->Text += String::Format("\nYou can contact Dr.{0} to make an appointment\nPhone Number: {1}", name, phone);
                 label19->Show();
                 if (index_related == Related_Diseases.size()) {
                     button2->Text = "End";
                     check1 = true;
                 }
                 index_related++;
             }
         }
     }
}
private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {
    if (button3->Text == "End") {
        label12->Show();
        label8->Show();
        label9->Show();
        label16->Show();
        pictureBox10->Show();
        pictureBox11->Show();
        pictureBox12->Show();
        pictureBox13->Show();
        pictureBox14->Show();
        pictureBox15->Show();
        label18->Hide();
        button2->Hide();
        textBox4->Hide();
        textBox4->Text = "";
        label17->Hide();
        label19->Hide();
        button3->Hide();
        Back_P->Hide();
    }
    else if (button3->Text == "Next") {
        string y;
        if (textBox4->Text != "") {
            MarshalString(textBox4->Text, y);
            if (stoi(y) < 1 || stoi(y) > allDiseases.size()) {
                label18->Text = "please enter the correct number for the Disease";
                label18->Show();
            }
            else {
                label18->Hide();
                label19->Text = "";
                label17->Text = "";
                String^ str2 = gcnew String(allDiseases[stoi(y) - 1].name.c_str());
                String^ info = gcnew String(allDiseases[stoi(y) - 1].info.c_str());
                label17->Text = String::Format("Viewing {0}", str2);
                label19->Text += String::Format("General Information:\n{0}\nSymptoms:", info);
                if (allDiseases[stoi(y) - 1].symps.size() > 0) {
                    for (int i = 1; i <= allDiseases[stoi(y) - 1].symps.size(); i++) {
                        String^ index = gcnew String(to_string(i).c_str());
                        String^ str2 = gcnew String(allDiseases[stoi(y) - 1].symps[i - 1].c_str());
                        if (i % 5 == 0)
                            label19->Text += String::Format("{0}-{1}\n", index, str2);
                        else label19->Text += String::Format("{0}-{1}     ", index, str2);

                    }
                }
                else {
                    label19->Text += String::Format("\nNo symptoms for this disease yet.");
                }
                String^ name = gcnew String(allDiseases[stoi(y) - 1].doc_name.c_str());
                String^ phone = gcnew String(allDiseases[stoi(y) - 1].doc_phone.c_str());
                label19->Text += String::Format("\nYou can contact Dr.{0}\nPhone Number: {1}", name, phone);
                label19->Show();
                
                button3->Text = "End";
                textBox4->Text = "";
                textBox4->Hide();

            }
        }
    }
}
private: System::Void panel5_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void pictureBox22_Click(System::Object^ sender, System::EventArgs^ e) {
    button4->Text = "Next";
    pictureBox30->Hide();
    view_Patients();
    textBox5->Show();
    button4->Show();
    button6->Show();
    pictureBox19->Hide();
    pictureBox22->Hide();
    pictureBox23->Hide();
    pictureBox24->Hide();
    pictureBox25->Hide();
    pictureBox26->Hide();
    pictureBox29->Hide();
    pictureBox28->Hide();
    label22->Hide();
    label23->Hide();
    label24->Hide();
    label25->Hide();
    label26->Hide();
    label27->Hide();
    label30->Hide();
}
private: System::Void pictureBox27_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void pictureBox20_Click(System::Object^ sender, System::EventArgs^ e) {
    panel4->TabIndex -= 5;
    if (MessageBox::Show("Are you sure you want to Logout?", "Logout?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
        logout_back();
    }
}
private: System::Void pictureBox21_Click(System::Object^ sender, System::EventArgs^ e) {
    textBox5->Show();
    button4->Show();
    button6->Show();
    pictureBox19->Hide();
    pictureBox22->Hide();
    pictureBox23->Hide();
    pictureBox24->Hide();
    pictureBox25->Hide();
    pictureBox26->Hide();
    pictureBox29->Hide();
    pictureBox28->Hide();
    label22->Hide();
    label23->Hide();
    label24->Hide();
    label25->Hide();
    label26->Hide();
    label27->Hide();
    label30->Hide();
}
private: System::Void pictureBox19_Click(System::Object^ sender, System::EventArgs^ e) {
    display_All_diseases();
    pictureBox30->Hide();
    button4->Text = "Next";
    textBox5->Show();
    button4->Show();
    button6->Show();
    pictureBox19->Hide();
    pictureBox22->Hide();
    pictureBox23->Hide();
    pictureBox24->Hide();
    pictureBox25->Hide();
    pictureBox26->Hide();
    pictureBox29->Hide();
    pictureBox28->Hide();
    label22->Hide();
    label23->Hide();
    label24->Hide();
    label25->Hide();
    label26->Hide();
    label27->Hide();
    label30->Hide();
}
private: System::Void textBox5_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
    char ch = e->KeyChar;
	if (!isdigit(ch) && ch != 8)
	{
		e->Handled = true;
	}
}
private: System::Void pictureBox21_Click_1(System::Object^ sender, System::EventArgs^ e) {
    panel4->TabIndex -= 5;
    System::Windows::Forms::SendKeys::Send("%");
    /*if (MessageBox::Show("Are you sure you want to quit?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
        writeAllPatients(allPatients);
        writeAllDiseases(allDiseases);
        writeAllDoctors(allDoctors);
    }*/
        this->Close();
}
private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {
    bool check_duplicate = true;
    int k = 0;
    bool check = true;
    string x;
    if (button4->Text == "Next") {
        if (label29->Text == "Choose the disease you want to view.") {
            if (textBox5->Text != "") {
                MarshalString(textBox5->Text, x);
                textBox5->Text = "";
                if (stoi(x) > allDiseases.size()) {
                    label32->Text = "Invalid Entry";
                    label32->Show();
                }
                else {
                    label32->Hide();
                    String^ str2 = gcnew String(allDiseases[stoi(x) - 1].name.c_str());
                    String^ info = gcnew String(allDiseases[stoi(x) - 1].info.c_str());
                    label29->Text = String::Format("Viewing {0}", str2);
                    label28->Text = String::Format("General Information:\n{0}\nSymptoms:", info);
                    if (allDiseases[stoi(x) - 1].symps.size() > 0) {
                        for (int j = 1; j <= allDiseases[stoi(x) - 1].symps.size(); j++) {
                            string symp = allDiseases[stoi(x) - 1].symps[j - 1];
                            String^ symptom = gcnew String(symp.c_str());
                            String^ index1 = gcnew String(to_string(j).c_str());
                            if (j == 1 || j % 5 == 0) label28->Text += String::Format("\n{0}-{1}", index1, symptom);
                            else label28->Text += String::Format("     {0}-{1}", index1, symptom);
                        }
                    }
                    else {
                        label28->Text += String::Format("\nNo symptoms for this disease yet.");
                    }
                    String^ name = gcnew String(allDiseases[stoi(x) - 1].doc_name.c_str());
                    String^ phone = gcnew String(allDiseases[stoi(x) - 1].doc_phone.c_str());
                    label28->Text += String::Format("\nYou can contact Dr.{0}\nPhone Number: {1}", name, phone);
                    label28->Show();
                    button4->Text = "End";
                    textBox5->Hide();
                }

            }
        }
        else if (label29->Text == "Which Disease you want to display its Patients?") {
            if (textBox5->Text != "") {
                MarshalString(textBox5->Text, x);
                textBox5->Text = "";
                vector<string> Patient_with_Disease;
                for (int i = 0; i < index_allPatients; i++) {
                    for (int j = 0; j < allPatients[i].Disease_History.size(); j++) {
                        if (allDiseases[stoi(x) - 1].name == allPatients[i].Disease_History[j]) {
                            Patient_with_Disease.push_back(allPatients[i].patient_name);
                        }

                    }
                }
                if (Patient_with_Disease.size() == 0) {
                    String^ str2 = gcnew String(allDiseases[stoi(x) - 1].name.c_str());
                    label29->Text = String::Format("There's no patients diagnosed with {0}", str2);
                    label28->Text = "";
                    label28->Hide();
                    button4->Text = "End";
                    textBox5->Hide();
                }
                else {
                    String^ str2 = gcnew String(allDiseases[stoi(x) - 1].name.c_str());
                    label29->Text = String::Format("Patients with {0} are.", str2);
                    label28->Text = "";
                    for (int i = 1; i <= Patient_with_Disease.size(); i++) {
                        String^ index = gcnew String(to_string(i).c_str());
                        String^ str3 = gcnew String(Patient_with_Disease[i].c_str());
                        if (i==1||i%5==0)
                            label28->Text += String::Format("{0}-{1}\n", index, str3);
                        else 
                            label28->Text += String::Format("{0}-{1}     ", index, str3);


                    }
                    label28->Show();
                    button4->Text = "End";
                    textBox5->Hide();
                }
            }
        }
        else if (label31->Text == "Please enter the disease name:") {
            if (textBox6->Text != "") {
                MarshalString(textBox6->Text, disease_name);
                textBox6->Text = "";
                check_disease_name(disease_name);
                label32->Show();
                if (check_disease_name(disease_name) == false) {
                    label31->Text = "Please enter General info about this disease:";
                    label32->Hide();
                }
            }
        }
        else if (label31->Text == "Please enter General info about this disease:") {
            if (textBox6->Text != "") {
                MarshalString(textBox6->Text, disease_info);
                textBox6->Text = "";
                label31->Text = "Please enter number of symptoms:";
                textBox6->Hide();
                textBox5->Show();
            }
        }

        else if (label31->Text == "Please enter number of symptoms:") {
            index_symp = 1;
            if (textBox5->Text != "") {
                textBox6->Show();
                MarshalString(textBox5->Text, sympnum);
                if (stoi(sympnum) == 0) {
                    if (MessageBox::Show("Are you sure you do not want to add symptoms", "symptoms?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                        (*CurrentDoctor).doc_diseases.push_back({ disease_name,disease_info,allsymps, (*CurrentDoctor).doc_name, (*CurrentDoctor).phone });
                        Diseases newDisease = { disease_name,disease_info,allsymps, (*CurrentDoctor).doc_name, (*CurrentDoctor).phone };
                        allDiseases.push_back(newDisease);
                        extract_New_Symptoms(newDisease);
                        disease_name = "";
                        disease_info = "";
                        button4->Text = "End";
                        button4->PerformClick();
                        button4->Text = "Next";
                        label31->Text = "Weeeeeeeee";
                        label31->Hide();
                    }
                }
                else {
                    label31->Text = String::Format("Symptom #1");
                    label31->Show();
                    if (index_symp == stoi(sympnum)) {
                        button4->Text = "End";
                    }
                }
            }
        }


        else if (label31->Text != "") {
            if (label31->Text[0] == 'S') {
                if (index_symp <= stoi(sympnum)) {
                    if (textBox6->Text != "") {
                        textBox5->Hide();
                        textBox6->Show();
                        string symp;
                        MarshalString(textBox6->Text, symp);
                        textBox6->Text = "";
                        bool check2 = true;
                        if (index_symp != 1) {
                            for (int j = 0; j < allsymps.size(); j++) {
                                if (symp == allsymps[j]) {
                                    check2 = false;
                                    label32->Text = "you added this symptom before";
                                    label32->Show();
                                    break;
                                }

                            }
                        }
                        if (check2) {
                            label32->Hide();
                            allsymps.push_back(symp);
                            index_symp++;
                            String^ index = gcnew String(to_string(index_symp).c_str());
                            label31->Text = String::Format("Symptom #{0}", index);
                            label31->Show();
                        }
                    }
                }
                if (index_symp == stoi(sympnum)) {
                    button4->Text = "End";
                }
            }
        }
        else if (label29->Text == "Please choose Which disease you want\nto add its symptoms....") {
            if (textBox5->Text != "") {
                bool check2 = true;
                MarshalString(textBox5->Text, menuChoice);
                if (stoi(menuChoice) > (*CurrentDoctor).doc_diseases.size()) {

                    check2 = false;
                    label32->Text = "Invalid entry";
                    label32->Show();
                }
                else  if (stoi(menuChoice) == 0) {
                    check2 = false;
                    label32->Text = "Invalid entry";
                    label32->Show();
                }
                if (check2) {
                    button4->Text = "End.";
                    label32->Hide();
                    diseaseChoice = stoi(menuChoice) - 1;
                    bool check_duplicate = true;
                    String^ index = gcnew String(to_string((*CurrentDoctor).doc_diseases[diseaseChoice].symps.size() + 1).c_str());
                    String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[diseaseChoice].name.c_str());
                    label31->Text = String::Format("You are adding symptom number {0} to {1}", index, str2);
                    label31->Show();
                    textBox5->Hide();
                    textBox6->Show();
                    label29->Hide();
                    label28->Hide();
                }
            }
        }

        else if (label29->Text == "Please choose Which disease you want to delete..") {
            int disease_choice;
            if (textBox5->Text != "") {
                bool check3 = true;
                MarshalString(textBox5->Text, menuChoice);
                if (stoi(menuChoice) > (*CurrentDoctor).doc_diseases.size()) {
                    check3 = false;
                    label32->Text = "Invalid entry";
                    label32->Show();
                }
                else  if (stoi(menuChoice) == 0) {
                    check3 = false;
                    label32->Text = "Invalid entry";
                    label32->Show();
                }
                disease_choice = stoi(menuChoice) - 1;
                if (check3) {
                    String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[disease_choice].name.c_str());
                    if (MessageBox::Show(String::Format("Are you sure you want to delete {0}",str2),str2, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                    remove_symptom_from_all_Symptoms((*CurrentDoctor).doc_diseases[disease_choice]);
                    remove_Disease_from_all_Diseases((*CurrentDoctor).doc_diseases[disease_choice]);
                    (*CurrentDoctor).doc_diseases.erase((*CurrentDoctor).doc_diseases.begin() + disease_choice);
                    button4->Text = "End";
                    button4->PerformClick();
                    button4->Text = "Next";
                    }
                }
            }
        }
        else if (label29->Text == "Please choose Which disease you want\nto delete its symptoms..") {
            if (textBox5->Text != "") {
                bool check3 = true;
                MarshalString(textBox5->Text, menuChoice);
                int diseaseChoice, symptomChoice;
                if (stoi(menuChoice) > (*CurrentDoctor).doc_diseases.size()) {
                    label32->Text = "Invalid Entry";
                    label32->Show();
                    check3 = true;
                }
                else  if (stoi(menuChoice) == 0) {
                    label32->Text = "Invalid Entry";
                    label32->Show();
                    check3 = true;
                }


                diseaseChoice = stoi(menuChoice) - 1;

                if (check3) {
                    label32->Hide();
                    textBox5->Text = "";
                    if ((*CurrentDoctor).doc_diseases[diseaseChoice].symps.size() == 0) {
                        label31->Text = "there is no Symptoms for this disease";
                        label31->Show();
                        label28->Hide();
                        label29->Hide();
                        label29->Text="wEEE";
                        textBox5 -> Hide();
                        button4->Text = "End";
                    }
                    else {

                        label28->Text = "";
                        //displaying all the symptoms of the chosen disease to choose among the them
                        for (int i = 0; i < (*CurrentDoctor).doc_diseases[diseaseChoice].symps.size(); i++) {
                            String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[diseaseChoice].symps[i].c_str());
                            String^ index = gcnew String(to_string(i + 1).c_str());
                            if (i % 5 == 0 && i != 0)
                                label28->Text += String::Format("{0}-{1}\n", index, str2);
                            else
                                label28->Text += String::Format("{0}-{1}     ", index, str2);
                        }
                        label28->Show();


                        label29->Text = "Please choose Which symptom you want to remove ....";
                        label29->Show();
                    }
                }
            }
        }
                else if (label29->Text == "Please choose Which symptom you want to remove ....") {
                    if (textBox5->Text != "") {
                        MarshalString(textBox5->Text, menuChoice);
                        bool check4 = true;


                        if (stoi(menuChoice) > (*CurrentDoctor).doc_diseases[diseaseChoice].symps.size()) {
                            label32->Text = "Invalid Entry";
                            label32->Show();
                            check4 = true;
                        }
                        else  if (stoi(menuChoice) == 0) {
                            label32->Text = "Invalid Entry";
                            label32->Show();
                            check4 = true;
                        }
                        symptom_Choice = stoi(menuChoice) - 1;
                        if (check4) {
                            String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[diseaseChoice].symps[symptom_Choice].c_str());
                            if (MessageBox::Show(String::Format("Are you sure you want to delete {0}", str2), str2, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                                remove_symptom_from_all_Disease((*CurrentDoctor).doc_diseases[diseaseChoice], symptom_Choice);
                                remove_symptom_from_all_Symptoms((*CurrentDoctor).doc_diseases[diseaseChoice], symptom_Choice);
                                (*CurrentDoctor).doc_diseases[diseaseChoice].symps.erase((*CurrentDoctor).doc_diseases[diseaseChoice].symps.begin() + symptom_Choice);
                                button4->Text = "End";
                                button4->PerformClick();
                                button4->Text = "Next";
                                symptom_Choice = 0;
                            }
                        }
                    }
                }
        
}

    else if (button4->Text == "End.") {
        if (textBox6->Text != "") {
            MarshalString(textBox6->Text, symptom_info);
            bool check_duplicate1 = true;
            for (int i = 0; i < (*CurrentDoctor).doc_diseases[diseaseChoice].symps.size(); i++) {
                if ((*CurrentDoctor).doc_diseases[diseaseChoice].symps[i] == symptom_info) {
                    label32->Text = ("This symptom is already added before");
                    label32->Show();
                    check_duplicate1 = false;
                }
            }

            if (check_duplicate1) {
                (*CurrentDoctor).doc_diseases[diseaseChoice].symps.push_back(symptom_info);
                extract_New_Symptoms((*CurrentDoctor).doc_diseases[diseaseChoice]);
                extract_New_Symptoms_to_alldiseases((*CurrentDoctor).doc_diseases[diseaseChoice]);
                label31->Text = "weeeeeeee";
                label31->Hide();
                textBox5->Text = "";
                textBox5->Hide();
                button4->Hide();
                button6->Hide();
                label28->Hide();
                pictureBox19->Show();
                pictureBox22->Show();
                pictureBox23->Show();
                pictureBox24->Show();
                pictureBox25->Show();
                pictureBox26->Show();
                pictureBox29->Show();
                pictureBox28->Show();
                pictureBox30->Show();

                label22->Show();
                label23->Show();
                label24->Show();
                label25->Show();
                label26->Show();
                label27->Show();
                label30->Show();
                label31->Hide();
                textBox6->Text = "";
                textBox6->Hide();
                label29->Text = "";
                label29->Hide();
            }
        }
    }
        else if (button4->Text == "End" && index_symp == stoi(sympnum)) {
            if (textBox6->Text != "") {
                textBox5->Hide();
                textBox6->Show();
                string symp;
                MarshalString(textBox6->Text, symp);
                textBox6->Text = "";
                bool check2 = true;
                if (index_symp != 1) {
                    for (int j = 0; j < allsymps.size(); j++) {
                        if (symp == allsymps[j]) {
                            check2 = false;
                            label32->Text = "you added this symptom before";
                            label32->Show();
                            break;
                        }

                    }
                }
                if (check2) {
                    allsymps.push_back(symp);
                    (*CurrentDoctor).doc_diseases.push_back({ disease_name,disease_info,allsymps, (*CurrentDoctor).doc_name, (*CurrentDoctor).phone });
                    Diseases newDisease = { disease_name,disease_info,allsymps, (*CurrentDoctor).doc_name, (*CurrentDoctor).phone };
                    allDiseases.push_back(newDisease);
                    extract_New_Symptoms(newDisease);
                    disease_name = "";
                    disease_info = "";
                    label31->Text = "weeeeeeee";
                    label31->Hide();
                    sympnum = "0";
                    allsymps.clear();
                    textBox5->Text = "";
                    textBox5->Hide();
                    button4->Hide();
                    button6->Hide();
                    label28->Hide();
                    pictureBox19->Show();
                    pictureBox22->Show();
                    pictureBox23->Show();
                    pictureBox24->Show();
                    pictureBox25->Show();
                    pictureBox26->Show();
                    pictureBox29->Show();
                    pictureBox28->Show();
                    label22->Show();
                    label23->Show();
                    label24->Show();
                    label25->Show();
                    label26->Show();
                    label27->Show();
                    label30->Show();
                    label31->Hide();
                    textBox6->Text = "";
                    textBox6->Hide();
                    pictureBox30->Show();

                }
            }
        }

        else {
            textBox5->Text = "";
            textBox5->Hide();
            button4->Hide();
            button6->Hide();
            label28->Hide();
            pictureBox19->Show();
            pictureBox22->Show();
            pictureBox23->Show();
            pictureBox24->Show();
            pictureBox25->Show();
            pictureBox26->Show();
            pictureBox29->Show();
            pictureBox28->Show();
            label22->Show();
            label23->Show();
            label24->Show();
            label25->Show();
            label26->Show();
            label27->Show();
            label30->Show();
            label31->Hide();
            textBox6->Text = "";
            textBox6->Hide();
            label29->Text = "";
            label29->Hide();
            pictureBox30->Show();
        }
    
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {
        if (label29->Text[0] == 'V') { //Viewing disease kaza
            button4->Text = "Next";
            display_All_diseases();
            textBox5->Show();
            button4->Show();
            button6->Show();
            pictureBox19->Hide();
            pictureBox22->Hide();
            pictureBox23->Hide();
            pictureBox24->Hide();
            pictureBox25->Hide();
            pictureBox26->Hide();
            pictureBox29->Hide();
            pictureBox28->Hide();
            label22->Hide();
            label23->Hide();
            label24->Hide();
            label25->Hide();
            label26->Hide();
            label27->Hide();
            label30->Hide();
            label29->Text == "Choose the disease you want to view.";
        }
    
    else if (label29->Text[0] == 'C' || label29->Text[0] == 'W'|| label31->Text == "Please enter the disease name:"||label29->Text == "Please choose Which disease you want\nto add its symptoms...."|| label29->Text == "Please choose Which disease you want\nto delete its symptoms..") { //Choose disease to view
        pictureBox30->Show();
        label32->Hide();
        textBox6->Text = "";
        textBox5->Hide();
        textBox6->Hide();
        button4->Hide();
        button6->Hide();
        label28->Hide();
        label29->Hide();
        pictureBox19->Show();
        pictureBox22->Show();
        pictureBox23->Show();
        pictureBox24->Show();
        pictureBox25->Show();
        pictureBox26->Show();
        pictureBox29->Show();
        pictureBox28->Show();
        label22->Show();
        label23->Show();
        label24->Show();
        label25->Show();
        label26->Show();
        label27->Show();
        label30->Show();
        label31->Hide();
    }
     if (label29->Text[0] == 'T' || label29->Text[1] == 'a') {
        label29->Text = "Which Disease you want to display its Patients?";
        button4->Text = "Next";
        view_Patients();
        textBox5->Show();
        button4->Show();
        button6->Show();
        pictureBox19->Hide();
        pictureBox22->Hide();
        pictureBox23->Hide();
        pictureBox24->Hide();
        pictureBox25->Hide();
        pictureBox26->Hide();
        pictureBox29->Hide();
        pictureBox28->Hide();
        label22->Hide();
        label23->Hide();
        label24->Hide();
        label25->Hide();
        label26->Hide();
        label27->Hide();
        label30->Hide();
    }
    else if (label31->Text == "Please enter General info about this disease:") {
        label31->Text = "Please enter the disease name:";
        textBox6->Text = "";
    }
    else if (label31->Text=="Please enter number of symptoms:") {
        label31->Text = "Please enter General info about this disease:";;
        textBox5->Hide();
        textBox5->Text = "";
        textBox6->Text = "";
        textBox6->Show();
    }
    if (label31->Text[8] == '#' && index_symp == 1) {
        label31->Text = "Please enter number of symptoms:";
        textBox6->Text = "";
        textBox5->Text = "";
        textBox5->Show();
        textBox6->Hide();
        button4->Text = "Next";
        if (index_symp == allsymps.size()) {
            allsymps.erase(allsymps.begin() + (index_symp - 1));
        }
    }
    else if (index_symp != 1) {
        if (index_symp == allsymps.size()) {
            allsymps.erase(allsymps.begin()+(index_symp-1));
        }
        index_symp--;
        String^ index = gcnew String(to_string(index_symp).c_str());
        label31->Text = String::Format("Symptom #{0}", index);
        textBox5->Text = "";
        button4->Text = "Next";
    }
    else if (label31->Text =="there is no Symptoms for this disease"|| label29->Text == "Please choose Which symptom you want to remove ....") {
    label29->Text = "Please choose Which disease you want\nto delete its symptoms..";
    label31->Text = "weeeeeeeeee";
    label31->Hide();
    button4->Text="Next";
    label29->Show();
    label28->Show();
    textBox5->Show();
}
    else if (symptom_Choice > 0) {
    label29->Text = "Please choose Which disease you want\nto delete its symptoms..";
}
    
    }
private: System::Void pictureBox26_Click(System::Object^ sender, System::EventArgs^ e) {
    label31->Text = "Please enter the disease name:";
    pictureBox30->Hide();
    label31->Show();
    button4->Text = "Next";
    textBox6->Show();
    textBox5->Hide();
    button4->Show();
    button6->Show();
    pictureBox19->Hide();
    pictureBox22->Hide();
    pictureBox23->Hide();
    pictureBox24->Hide();
    pictureBox25->Hide();
    pictureBox26->Hide();
    pictureBox29->Hide();
    pictureBox28->Hide();
    label22->Hide();
    label23->Hide();
    label24->Hide();
    label25->Hide();
    label26->Hide();
    label27->Hide();
    label30->Hide();
}
private: System::Void pictureBox28_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox24_Click(System::Object^ sender, System::EventArgs^ e) {
    button4->Text = "Next";
    add_Symptom();
    button4->Show();
    pictureBox19->Hide();
    pictureBox22->Hide();
    pictureBox23->Hide();
    pictureBox24->Hide();
    pictureBox25->Hide();
    pictureBox26->Hide();
    pictureBox29->Hide();
    pictureBox28->Hide();
    label22->Hide();
    label23->Hide();
    label24->Hide();
    label25->Hide();
    label26->Hide();
    label27->Hide();
    label30->Hide();
    pictureBox30->Hide();
}
private: System::Void pictureBox25_Click(System::Object^ sender, System::EventArgs^ e) {
    remove_disease();
    pictureBox30->Hide();
    button4->Show();
    pictureBox19->Hide();
    pictureBox22->Hide();
    pictureBox23->Hide();
    pictureBox24->Hide();
    pictureBox25->Hide();
    pictureBox26->Hide();
    pictureBox29->Hide();
    pictureBox28->Hide();
    label22->Hide();
    label23->Hide();
    label24->Hide();
    label25->Hide();
    label26->Hide();
    label27->Hide();
    label30->Hide();
}
private: System::Void pictureBox23_Click(System::Object^ sender, System::EventArgs^ e) {
    remove_Symptom();
    pictureBox30->Hide();
    button4->Show();
    pictureBox19->Hide();
    pictureBox22->Hide();
    pictureBox23->Hide();
    pictureBox24->Hide();
    pictureBox25->Hide();
    pictureBox26->Hide();
    pictureBox29->Hide();
    pictureBox28->Hide();
    label22->Hide();
    label23->Hide();
    label24->Hide();
    label25->Hide();
    label26->Hide();
    label27->Hide();
    label30->Hide();
}
private: System::Void label28_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox30_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox12_Click_1(System::Object^ sender, System::EventArgs^ e) {
    label12->Hide();
    label8->Hide();
    label9->Hide();
    label16->Hide();
    pictureBox10->Hide();
    pictureBox11->Hide();
    pictureBox12->Hide();
    pictureBox13->Hide();
    pictureBox14->Hide();
    pictureBox15->Hide();
    label19->Show();
    viewhist();
    button3->Show();
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {
    if (label17->Text == "Please enter the symptoms you are currently feeling.\nWhen you are done, enter 0\n") {
        label12->Show();
        label8->Show();
        label9->Show();
        label16->Show();
        pictureBox10->Show();
        pictureBox11->Show();
        pictureBox12->Show();
        pictureBox13->Show();
        pictureBox14->Show();
        pictureBox15->Show();
        textBox4->Hide();
        Back_P->Hide();
        label17->Hide();
        label19->Hide();
        button3->Hide();
        button2->Hide();
        textBox4->Hide();
   }
    else if (label17->Text == "please enter the number for the particular Disease.") {
        label12->Show();
        label8->Show();
        label9->Show();
        label16->Show();
        pictureBox10->Show();
        pictureBox11->Show();
        pictureBox12->Show();
        pictureBox13->Show();
        pictureBox14->Show();
        pictureBox15->Show();
        textBox4->Hide();
        Back_P->Hide();
        label17->Hide();
        label19->Hide();
        button3->Hide();
        button2->Hide();
        textBox4->Hide();
    }
    else if (label17->Text[0] == 'V') {
        Back_P->Show();
        label12->Hide();
        label8->Hide();
        label9->Hide();
        label16->Hide();
        pictureBox10->Hide();
        pictureBox11->Hide();
        pictureBox12->Hide();
        pictureBox13->Hide();
        pictureBox14->Hide();
        pictureBox15->Hide();
        display_Symptoms_for_Disease();
    }
    
}
private: System::Void button5_Click_1(System::Object^ sender, System::EventArgs^ e) {
    pictureBox13_Click(pictureBox13, e);
}
private: System::Void label33_Click(System::Object^ sender, System::EventArgs^ e) {
    Password->Text = "E-Mail";
    textBox2->Text = "";
    this->textBox2->PasswordChar = NULL;
    Next->Show();
    label33->Hide();
    button5->Show();
    button1->Hide();
    label2->Text="";
    label2->Hide();
    button5->Location = Drawing::Point(1180, 479);

}
private: System::Void label33_MouseHover(System::Object^ sender, System::EventArgs^ e) {
    label33->ForeColor = Color::FromArgb(255, 255, 255);
}
private: System::Void label33_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    label33->ForeColor = Color::FromArgb(0,0,0);
}
private: System::Void button5_Click_2(System::Object^ sender, System::EventArgs^ e) {
    if (Password->Text == "E-Mail"&&Username->Text=="Username") {
        button5->Hide();
        button1->Text = "Sign-in";
        this->textBox2->PasswordChar = '*';
        label33->Show();
        textBox1->Show();
        textBox3->Hide();
        label10->Hide();
        label3->Hide();
        label4->Hide();
        button1->Show();
        Username->Show();
        panel1->Show();
        panel2->Show();
        pictureBox6->Hide();
        pictureBox7->Hide();
        pictureBox8->Hide();
        pictureBox9->Hide();
        Sign_in->Show();
        textBox1->Text = "";
        textBox2->Text = "";
        Register->Text = "Register.";
        Username->Text = "Username";
        Password->Text = "Password";
        Next->Hide();
        Password->Show();
        textBox2->Show();
        textBox3->Show();
        label2->Hide();
        timer1->Start();
        Sign_in->Text = "Sign-in.";
        label2->Hide();
    }
    else if (Username->Text == "Please enter your Full Name.") {
        pictureBox6->Show();
        pictureBox7->Show();
        textBox1->Text = "";
        textBox1->Hide();
        Username->Hide();
        button5->Hide();
        Next->Hide();
        panel1->Hide();
        label3->Show();
        label4->Show();
        label2->Hide();

    }
    else if (Username->Text == "Username") {
        Username->Text = "Please enter your Full Name.";
        textBox1->Text = "";
        label2->Hide();
    }
    else if (Username->Text == "Password") {
        Username->Text = "Username";
        Password->Hide();
        textBox2->Hide();
        panel2->Hide();
    }
    else if (Username->Text == "Please select Age") {
        Username->Text = "Password";
        Password->Text = "Renter Password";
        textBox2->Show();
        panel2->Show();
        textBox1->Show();
        textBox3->Hide();
    }
    else if (Username->Text == "E-Mail"&&label11->Text=="p") {
        textBox3->Show();
        textBox1->Text = "";
        textBox1->Hide();
        Username->Text = "Please select Age";
        label2->Hide();
    }
    else if (Username->Text == "E-Mail" && label11->Text == "d") {
        textBox1->Hide();
        textBox1->Text="";
        textBox3->Show();
        textBox3->Text = "";
        Username->Text = "Mobile Phone Number";
        label2->Hide();
    }
    else if (button5->Location == Drawing::Point(1110, 479)) {
        label3->Hide();
        label4->Hide();
        label10->Hide();
        pictureBox8->Hide();
        pictureBox9->Hide();
        button5->Location = Drawing::Point(1180, 479);
        button8->Text = "No Profile Picture";
        button8->Show();
        pictureBox31->Show();
        button9->Show();
        Next->Show();
    }
    else if (Username->Text == "Mobile Phone Number") {
        Username->Text = "Password";
        Password->Text = "Renter Password";
        Password->Show();
        textBox2->Show();
        panel2->Show();
        textBox1->Show();
        textBox3->Hide();
        textBox3->Text="";
        textBox1->Text="";
        textBox2->Text="";
    }
    else if (Next->Text == "Capture"|| Next->Text == "Retake"||Next->Text== "Take a Picture") {
    Next->Text = "NEXT";
    button8->Hide();
    MyCamera->Stop();
    pictureBox31->Hide();
    label34->Hide();
    textBox1->Text = "";    
    Username->Text = "E-Mail";
    label2->Hide();
    button9->Hide();
    textBox1->Show();
}


    
}
private: System::Void pictureBox7_MouseHover(System::Object^ sender, System::EventArgs^ e) {
    label4->ForeColor = Color::FromArgb(54, 242, 242);
}
private: System::Void pictureBox7_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    label4->ForeColor = Color::FromArgb(255, 255, 255);
}
private: System::Void pictureBox6_MouseHover(System::Object^ sender, System::EventArgs^ e) {
    label3->ForeColor = Color::FromArgb(54, 242, 242); 
}
private: System::Void pictureBox6_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    label3->ForeColor = Color::FromArgb(255, 255, 255);
}
private: System::Void label6_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox3_MouseHover(System::Object^ sender, System::EventArgs^ e) {
    label5->ForeColor = Color::FromArgb(0, 0, 153);
    label6->ForeColor = Color::FromArgb(255, 255, 255);
}
private: System::Void pictureBox3_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    label5->ForeColor = Color::FromArgb(255, 255, 255);
}
private: System::Void pictureBox4_MouseHover(System::Object^ sender, System::EventArgs^ e) {
    label6->ForeColor = Color::FromArgb(0, 255, 128);
}
private: System::Void pictureBox4_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    label6->ForeColor = Color::FromArgb(255, 255, 255);
}
private: System::Void pictureBox5_MouseHover(System::Object^ sender, System::EventArgs^ e) {
    label7->ForeColor = Color::FromArgb(255, 0, 0);
}
private: System::Void pictureBox5_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
    label7->ForeColor = Color::FromArgb(255, 255, 255);

}
private: System::Void button8_Click(System::Object^ sender, System::EventArgs^ e) {

    if  (button8->Text == "End"||(button8->Text == "No Profile Picture"&&label11->Text=="d")) {
       

        if (button8->Text == "End") {
            string wow = "PICs\\Doctors\\" + doc_username + ".jpg";
            String^ str2 = gcnew String(wow.c_str());
            if (System::IO::File::Exists(str2)) {
                System::IO::File::Delete(str2);
            }
            pictureBox31->Image->Save(str2, ImageFormat::Jpeg);
        }
            label2->Hide();
            textBox3->Text = "";
            Doctors NewDoctor = { doc_name,{doc_username, doc_password, mail }, doctor_phone };
            allDoctors[index_allDoctors] = NewDoctor;
            CurrentDoctor = &allDoctors[index_allDoctors];
            index_allDoctors++;
            panel4->Show();
            panel5->Show();
            Form::Width -= 200;
            Form::Height -= 150;
            PrintDoctorMenu();
            label6->ForeColor = Color::FromArgb(255, 255, 255);
            label5->ForeColor = Color::FromArgb(255, 255, 255);
            label2->Hide();
            button8->Hide();
            button9->Hide();
            pictureBox31->Hide();
            button5->Hide();
    }
    else if (button8->Text == "Next"||label11->Text=="p") {
        label34->Hide();
        button8->Hide();
        pictureBox31->Hide();
        button9->Hide();
        pictureBox8->Show();
        pictureBox9->Show();
        panel1->Hide();


        textBox3->Hide();
        label2->Hide();

        label10->Show();
        label3->Text = "MALE";
        label4->Text = "FEMALE";
        label3->Show();
        label4->Show();
        Username->Text = "";
        button5->Location = Drawing::Point(1110, 479);
        Next->Hide();
        textBox1->Hide();
        panel2->Hide();
    }
}
private: System::Void pictureBox1_Click_1(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void pictureBox31_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void MyForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e) {
    MyCamera->Stop();
}
private: System::Void button9_Click(System::Object^ sender, System::EventArgs^ e) {
    OpenFileDialog^ dialog = gcnew OpenFileDialog();
    string filter = "Image Files(*.jpg; *.jpeg; *.gif; *.bmp)|*.jpg; *.jpeg; *.gif; *.bmp";
    String^ str3 = gcnew String(filter.c_str());
    dialog->Filter=str3 ;
    if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
        MyCamera->Stop();
        pictureBox31->ImageLocation = dialog->FileName;
        Next->Text = "Take a Picture";
        if (label11->Text == "p") {
            button8->Text = "Next";
        }
        else {
            button8->Text = "End";
        }
    }
 
}
private: System::Void textBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->KeyCode == Keys::Enter&&!panel4->Visible)
    {
        if (button1->Visible) {
            textBox2->Select();
        }
        else {
            Next->PerformClick();
        }
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}
private: System::Void textBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->KeyCode == Keys::Enter&&!panel4->Visible)
    {
        if (button1->Visible) {
            button1->PerformClick();
        }
        else {
            Next->PerformClick();
        }
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}
private: System::Void textBox3_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {

    if (e->KeyCode == Keys::Enter && !panel4->Visible)
    {
        Next->PerformClick();
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}
private: System::Void pictureBox32_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void pictureBox33_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Account_settings_Click(System::Object^ sender, System::EventArgs^ e) {

    Account_Settings^ sc = gcnew Account_Settings((*CurrentDoctor).doc_name, (*CurrentDoctor).account.username, (*CurrentDoctor).account.password, (*CurrentDoctor).account.email, (*CurrentDoctor).phone,(*CurrentDoctor).send_email, check_database, check_database_email, check_phone);
    this->Hide();
    sc->ShowDialog();
    this->Show();
    if(sc->save_key()){
        string wow = "PICs\\Doctors\\" + (*CurrentDoctor).account.username + ".jpg";
        String^ str3 = gcnew String(wow.c_str());
        if (System::IO::File::Exists(str3)) {
            pictureBox32->ImageLocation = str3;
        }
        else {
            pictureBox32->ImageLocation = "PICs\\guest.jpg";
        }
        label30->Text = "Hello Dr. "+ sc->GetFullname();
        MarshalString(sc->GetUsername(), (*CurrentDoctor).account.username);
        MarshalString(sc->GetPass(), (*CurrentDoctor).account.password);
        MarshalString(sc->GetFullname(), (*CurrentDoctor).doc_name);
        MarshalString(sc->GetEmail(), (*CurrentDoctor).account.email);
        MarshalString(sc->GetPhone(), (*CurrentDoctor).phone);
        (*CurrentDoctor).send_email =sc->Getsend_email();
    }
    if (sc->logout()) {
        logout_back();
    }

}
private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
    if (MessageBox::Show("Are you sure you want to quit?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) {
        e->Cancel = true;
    }
    else {
        writeAllPatients(allPatients);
        writeAllDiseases(allDiseases);
        writeAllDoctors(allDoctors);
        
    }
}
};
}
