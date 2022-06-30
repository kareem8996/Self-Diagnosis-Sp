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
char send_email='F';
string doc_name;
string pat_name;
string doc_username;
string pat_username;
string pat_password;
string doctor_phone = "";
string pat_phone = "";
string Pat_gender;
string doc_password;
string pat_age;
string mail;
string randomCode;
string PASSWORD;
string who_feed="";
bool Capture;
struct Accounts {
    string username;
    string password;
    string email;
};
struct Diseases {
    string name;
    string info;
    vector<string> symps;
    string doc_name;
    string doc_phone;

}CurrentDisease;
vector<Diseases> recently_deleted_diseases;

string sympnum = "0";
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
    string patient_phone;
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
vector<string> allUsernames = {};
vector<string> allPhones = {};
vector<string> allEmails = {};
void ValidatoryData() {
    for (int i = 0; i < index_allPatients; i++) {
        allUsernames.push_back(allPatients[i].account.username);
        //allPhones.push_back(allPatients[i].account.phone);
        allEmails.push_back(allPatients[i].account.email);
    }
    for (int i = 0; i < index_allDoctors; i++) {
        allUsernames.push_back(allDoctors[i].account.username);
        allEmails.push_back(allDoctors[i].account.email);
        allPhones.push_back(allDoctors[i].phone);
    }

}
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
        if (isalpha(username[j]))
            org2 += char(tolower(username[j]));
        else {
            org2 += username[j];
        }
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
    string org = "";
    for (int j = 0; j < email.size(); j++) {
        if (isalpha(email[j]))
            org += char(tolower(email[j]));
        else {
            org += email[j];
        }
    }
    string org2 = "";
    for (int i = 0; i < index_allDoctors; i++) {
        for (int j = 0; j < allDoctors[i].account.email.size(); j++) {
            if (isalpha(allDoctors[i].account.email[j]))
                org2+= char(tolower(allDoctors[i].account.email[j]));
            else {
                org2 += allDoctors[i].account.email[j];
            }
        }

        if (org==org2) {
            return false;
        }

    }
    org2 = "";
    for (int i = 0; i < index_allPatients; i++) {
        for (int j = 0; j < allPatients[i].account.email.size(); j++) {
            if (isalpha(allPatients[i].account.email[j]))
                org2 += char(tolower(allPatients[i].account.email[j]));
            else {
                org2 += allPatients[i].account.email[j];
            }
        }

        if (org == org2) {
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

int index_symp = 1;



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
        Image^ light_pic;
        Image^ dark_pic = Image::FromFile("PICs\\sys\\dark_mode.GIF");
        List<PictureBox^>^ backgrounds = gcnew List<PictureBox^>();
        List<Label^>^ recently_added_labels = gcnew List<Label^>();
        List<Label^>^ recently_deleted_labels = gcnew List<Label^>();
        List<PictureBox^>^ recently_added_pics = gcnew List<PictureBox^>();
        List<PictureBox^>^ recently_deleted_pics = gcnew List<PictureBox^>();
        bool open = false;
        bool open1 = false;
    private: System::Windows::Forms::PictureBox^ pictureBox20;
    public:
    private: System::Windows::Forms::PictureBox^ pictureBox33;
    private: System::Windows::Forms::PictureBox^ pictureBox34;
    private: System::Windows::Forms::Label^ label35;
    private: System::Windows::Forms::PictureBox^ pictureBox35;
    private: System::Windows::Forms::PictureBox^ pictureBox36;
    private: System::Windows::Forms::PictureBox^ pictureBox37;
    private: System::Windows::Forms::Label^ label36;
    private: System::Windows::Forms::PictureBox^ pictureBox38;
    private: System::Windows::Forms::PictureBox^ pictureBox39;
    private: System::Windows::Forms::PictureBox^ pictureBox40;
    private: System::Windows::Forms::PictureBox^ pictureBox41;
    private: System::Windows::Forms::Label^ label37;
    private: System::Windows::Forms::Label^ label38;
    private: System::Windows::Forms::PictureBox^ pictureBox42;
    private: System::Windows::Forms::PictureBox^ pictureBox43;
    private: System::Windows::Forms::Timer^ timer4;
    private: System::Windows::Forms::Timer^ timer5;
    private: System::Windows::Forms::Button^ delete_symps_button;
    private: System::Windows::Forms::Panel^ panel6;
    private: System::Windows::Forms::Button^ button10;
    private: System::Windows::Forms::Button^ clear_remove_list_button;
    private: System::Windows::Forms::Button^ Remove_all_symps_button;
    private: System::Windows::Forms::Button^ remove_symp_from_removed_button;
    private: System::Windows::Forms::Button^ add_symp_to_removed_button;
    private: System::Windows::Forms::ComboBox^ Current_doc_diseases_combobox;
    private: System::Windows::Forms::ListBox^ removed_symps_listbox;
    private: System::Windows::Forms::ListBox^ current_disease_symps_listbox;
    private: System::Windows::Forms::Button^ delete_diseases_button;
    private: System::Windows::Forms::Button^ clear_removed_diseases_button;
    private: System::Windows::Forms::Button^ remove_all_diseases_button;
    private: System::Windows::Forms::Button^ remove_disease_from_removed_button;
    private: System::Windows::Forms::Button^ add_disease_to_removed_button;
    private: System::Windows::Forms::ListBox^ removed_diseases_listbox;
    private: System::Windows::Forms::ListBox^ current_doctor_diseases_listbox;
    private: System::Windows::Forms::ComboBox^ Alldiseases_combobox;
    private: System::Windows::Forms::ListBox^ Patients_of_chosen_disease_listbox;
    private: System::Windows::Forms::TextBox^ Disease_doc_phone_textbox;
    private: System::Windows::Forms::TextBox^ Disease_docname_textbox;
    private: System::Windows::Forms::ListBox^ Disease_symps_listbox;
    private: System::Windows::Forms::TextBox^ Disease_info_textbox;
    private: System::Windows::Forms::TextBox^ Disease_name_textbox;
    private: System::Windows::Forms::Panel^ feed_panel;

    private: System::Windows::Forms::PictureBox^ third_most_picturebox;
    private: System::Windows::Forms::PictureBox^ second_most_picturebox;
    private: System::Windows::Forms::PictureBox^ Most_picturebox;
    private: System::Windows::Forms::PictureBox^ x_axis_picturebox;
    private: System::Windows::Forms::PictureBox^ y_axis_picturebox;
    private: System::Windows::Forms::PictureBox^ Recently_deleted_third_picturebox;
    private: System::Windows::Forms::PictureBox^ Recently_deleted_second_picturebox;
    private: System::Windows::Forms::PictureBox^ Recently_deleted_first_picturebox;
    private: System::Windows::Forms::PictureBox^ Recently_added_third_picturebox;
    private: System::Windows::Forms::PictureBox^ Recently_added_second_picturebox;
    private: System::Windows::Forms::PictureBox^ Recently_added_first_picturebox;
    private: System::Windows::Forms::Label^ Recently_deleted_third_label;
    private: System::Windows::Forms::Label^ Recently_deleted_second_label;
    private: System::Windows::Forms::Label^ Recently_deleted_first_label;
    private: System::Windows::Forms::Label^ Recently_added_third_label;
    private: System::Windows::Forms::Label^ Recently_added_second_label;
    private: System::Windows::Forms::Label^ Recently_added_first_label;
    private: System::Windows::Forms::Label^ Recently_deleted_label;
    private: System::Windows::Forms::Label^ Recently_added_label;
    private: System::Windows::Forms::Timer^ timer6;
    private: System::Windows::Forms::Timer^ timer7;
    private: System::Windows::Forms::Timer^ timer8;
    private: System::Windows::Forms::Timer^ timer9;
    private: System::Windows::Forms::Timer^ timer10;
    private: System::Windows::Forms::PictureBox^ second_most_front_picturebox;
    private: System::Windows::Forms::PictureBox^ third_most_front_picturebox;


    private: System::Windows::Forms::PictureBox^ most_front_picturebox;
    private: System::Windows::Forms::Label^ third_most_value;
    private: System::Windows::Forms::Label^ second_most_value;
    private: System::Windows::Forms::Label^ Most_value;
    private: System::Windows::Forms::Label^ Third_Most_name_label;
    private: System::Windows::Forms::Label^ Most_name_label;
    private: System::Windows::Forms::Label^ Second_Most_name_label;
    private: System::Windows::Forms::PictureBox^ back_feed_picturebox;
    private: System::Windows::Forms::Label^ Title_feed;

    private: System::Windows::Forms::PictureBox^ feed_background_dark;
    private: System::Windows::Forms::Label^ label13;
    private: Siticone::UI::WinForms::SiticoneWinToggleSwith^ email_togglebutton;








    private: System::Windows::Forms::PictureBox^ feed_background;



























    public:


    public:
        void Feed() {
            y_axis_picturebox->Hide();
            x_axis_picturebox->Hide();
            GraphicsPath^ gp = gcnew GraphicsPath();
            gp->AddEllipse(Recently_added_first_picturebox->DisplayRectangle);
            Recently_added_first_picturebox->Region = gcnew System::Drawing::Region(gp);

            GraphicsPath^ gp1 = gcnew GraphicsPath();
            gp1->AddEllipse(Recently_added_second_picturebox->DisplayRectangle);
            Recently_added_second_picturebox->Region = gcnew System::Drawing::Region(gp1);
            
            GraphicsPath^ gp2 = gcnew GraphicsPath();
            gp2->AddEllipse(Recently_added_third_picturebox->DisplayRectangle);
            Recently_added_third_picturebox->Region = gcnew System::Drawing::Region(gp2);

            GraphicsPath^ gp3 = gcnew GraphicsPath();
            gp3->AddEllipse(Recently_deleted_first_picturebox->DisplayRectangle);
            Recently_deleted_first_picturebox->Region = gcnew System::Drawing::Region(gp3);
            
            GraphicsPath^ gp4= gcnew GraphicsPath();
            gp4->AddEllipse(Recently_deleted_second_picturebox->DisplayRectangle);
            Recently_deleted_second_picturebox->Region = gcnew System::Drawing::Region(gp4);

            GraphicsPath^ gp5= gcnew GraphicsPath();
            gp5->AddEllipse(Recently_deleted_third_picturebox->DisplayRectangle);
            Recently_deleted_third_picturebox->Region = gcnew System::Drawing::Region(gp5);

            recently_added_labels->Add(Recently_added_first_label);
            recently_added_labels->Add(Recently_added_second_label);
            recently_added_labels->Add(Recently_added_third_label);
            recently_added_pics->Add(Recently_added_first_picturebox);
            recently_added_pics->Add(Recently_added_second_picturebox);
            recently_added_pics->Add(Recently_added_third_picturebox);

            for (int i = 1; i <= recently_added_labels->Count; i++) {
                String^ dis_name = gcnew String(allDiseases[allDiseases.size() - i].name.c_str());
                String^ doc_name = gcnew String(allDiseases[allDiseases.size() - i].doc_name.c_str());
                string doc_name_string = allDiseases[allDiseases.size() - i].doc_name;
                recently_added_labels[i - 1]->Text = String::Format("{0}\nhas been recently\ndiscovered by\n Dr.{1}", dis_name, doc_name);

                for (int j = 0; j < index_allDoctors; j++) {
                    if (allDoctors[j].doc_name == doc_name_string) {
                        string wow = "PICs\\Doctors\\" + allDoctors[j].account.username + ".jpg";
                        String^ str3 = gcnew String(wow.c_str());
                        if (System::IO::File::Exists(str3)) {
                            recently_added_pics[i - 1]->ImageLocation = str3;
                        }
                        else {
                            recently_added_pics[i - 1]->ImageLocation = "PICs\\guest.jpg";
                        }
                    }
                }
            }
            recently_deleted_labels->Add(Recently_deleted_first_label);
            recently_deleted_labels->Add(Recently_deleted_second_label);
            recently_deleted_labels->Add(Recently_deleted_third_label);
            recently_deleted_pics->Add(Recently_deleted_first_picturebox);
            recently_deleted_pics->Add(Recently_deleted_second_picturebox);
            recently_deleted_pics->Add(Recently_deleted_third_picturebox);

            if (recently_deleted_diseases.size() > 0) {
                for (int i = 1; i <= recently_deleted_diseases.size(); i++) {
                    String^ dis_name = gcnew String(recently_deleted_diseases[recently_deleted_diseases.size() - i].name.c_str());
                    String^ doc_name = gcnew String(recently_deleted_diseases[recently_deleted_diseases.size() - i].doc_name.c_str());
                    string doc_name_string = recently_deleted_diseases[recently_deleted_diseases.size() - i].doc_name;

                    recently_deleted_labels[i - 1]->Text = String::Format("{0} was recently deleted by Dr. {1}", dis_name, doc_name);

                    for (int j = 0; j < index_allDoctors; j++) {
                        if (allDoctors[j].doc_name == doc_name_string) {
                            string wow = "PICs\\Doctors\\" + allDoctors[j].account.username + ".jpg";
                            String^ str3 = gcnew String(wow.c_str());
                            if (System::IO::File::Exists(str3)) {
                                recently_deleted_pics[i - 1]->ImageLocation = str3;
                            }
                            else {
                                recently_deleted_pics[i - 1]->ImageLocation = "PICs\\guest.jpg";
                            }
                        }
                    }
                }


            }
            //getting the count of each disease
            vector<int> count;
            count.resize(allDiseases.size(), 0);
            for (int i = 0; i < index_allPatients; i++) {
                for (int j = 0; j < allDiseases.size(); j++) {
                    for (int k = 0; k < allPatients[i].Disease_History.size(); k++) {
                        if (allPatients[i].Disease_History[k] == allDiseases[j].name) {
                            count[j]++;
                        }
                    }
                }
            }
            //check the highest three
            int max = 0,
                second_max = 0,
                third_max = 0;
            string most_name="", second_most_name = "", third_most_name = "";
            for (int i = 0; i < count.size(); i++) {
                if (count[i] > max) {
                    third_max = second_max;
                    second_max = max;
                    max = count[i];
                    third_most_name = second_most_name;
                    second_most_name = most_name;
                    most_name = allDiseases[i].name;

                }
                else if (count[i] > second_max) {
                    third_max = second_max;
                    second_max = count[i];
                    third_most_name = second_most_name;
                    second_most_name = allDiseases[i].name;
                }
                else if (count[i] > third_max) {
                    third_max = count[i];
                    third_most_name = allDiseases[i].name;
                }
            }
            String^ Max = gcnew String(to_string(max).c_str());
            String^ second_Max = gcnew String(to_string(second_max).c_str());
            String^ third_Max = gcnew String(to_string(third_max).c_str());
            Most_value->Text = Max;
            second_most_value->Text = second_Max;
            third_most_value->Text = third_Max;

            Max = gcnew String(most_name.c_str());
            second_Max = gcnew String(second_most_name.c_str());
            third_Max = gcnew String(third_most_name.c_str());
            Most_name_label->Text= Max;
            Second_Most_name_label->Text = second_Max;
            Third_Most_name_label->Text = third_Max;

        }
        void add_to_recently_deleted(Diseases dis) {
            if (recently_deleted_diseases.size() < 3) {
                recently_deleted_diseases.push_back(dis);
            }
            else {
                recently_deleted_diseases.erase(recently_deleted_diseases.begin());
                recently_deleted_diseases.push_back(dis);
            }
        }

        Camera^ MyCamera = gcnew Camera();

        void MarshalString(String^ s, string& os) {
            using namespace Runtime::InteropServices;
            const char* chars =
                (const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
            os = chars;
            Marshal::FreeHGlobal(IntPtr((void*)chars));
        }
        static String^ Code;

    private: System::Windows::Forms::Button^ button8;
    private: System::Windows::Forms::Label^ label34;
    private: System::Windows::Forms::Button^ button9;
    private: System::Windows::Forms::PictureBox^ pictureBox32;


    private: System::Windows::Forms::PictureBox^ pictureBox31;

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
            who_feed = "p";
            String^ str2 = gcnew String((*CurrentPatient).patient_name.c_str());
            if ((*CurrentPatient).gender == 'f' || (*CurrentPatient).gender == 'F') {
                label15->Text = String::Format("Hello Ms/Mrs.{0}", str2);
            }
            else label15->Text = String::Format("Hello Mr.{0}", str2);
            string wow = "PICs\\Patients\\" + (*CurrentPatient).account.username + ".jpg";
            String^ str3 = gcnew String(wow.c_str());
            if (System::IO::File::Exists(str3)) {
                pictureBox37->ImageLocation = str3;
                pictureBox43->ImageLocation = str3;
            }
            else {
                pictureBox37->ImageLocation = "PICs\\guest.jpg";
                pictureBox43->ImageLocation = "PICs\\guest.jpg";
            }
        }
        void view_all_Symptoms() {
            label17->Text = "Please enter the symptoms you are currently feeling.\nWhen you are done, enter 0\n";
            label17->Show();
            label19->Text = "";
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
                label19->Text += "You do not have a Diagnosis History";
            else {
                label19->Text += "The diseases you were diagnosed with are:\n";
                for (int i = 1; i <= (*CurrentPatient).Disease_History.size(); i++) {
                    String^ index = gcnew String(to_string(i).c_str());
                    String^ str2 = gcnew String((*CurrentPatient).Disease_History[i - 1].c_str());
                    label19->Text += String::Format("{0}-{1}\n", index, str2);
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
                label17->Text = "You are not diagnosed with any Diseases, but here is the closest disease related to your symptoms:\n";
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
                        label32->Text = String::Format("Unfortunately this disease was added by Dr.{0}\nfor further info you can contact him on:", str2, str3);
                        label32->Show();
                        return true;

                    }
                }
            }
            return false;
        }
        void PrintDoctorMenu() {
            who_feed = "d";
            String^ str2 = gcnew String((*CurrentDoctor).doc_name.c_str());
            label30->Text = String::Format("Hello Dr.{0}", str2);
            string wow = "PICs\\Doctors\\" + (*CurrentDoctor).account.username + ".jpg";
            String^ str3 = gcnew String(wow.c_str());
            if (System::IO::File::Exists(str3)) {
                pictureBox32->ImageLocation = str3;
                pictureBox36->ImageLocation = str3;
            }
            else {
                pictureBox32->ImageLocation = "PICs\\guest.jpg";
                pictureBox36->ImageLocation = "PICs\\guest.jpg";
            }
        }
        void display_All_diseases() {
            string choice;
            bool check;        int viewChoice = -1;
            label29->Text = "Choose the disease you want to view.";
            label29->Show();
            label28->Text = "";
            label28->Show();
            textBox4->Show();
            Alldiseases_combobox->Items->Clear();
            for (int i = 1; i <= allDiseases.size(); i++) {
                String^ str2 = gcnew String(allDiseases[i - 1].name.c_str());
                String^ index = gcnew String(to_string(i).c_str());
                /* if (i % 5 == 0 || i == allDiseases.size())
                     label28->Text += String::Format("{0}-{1}\n", index, str2);
                 else
                     label28->Text += String::Format("{0}-{1}     ", index, str2);*/
                Alldiseases_combobox->Items->Add(str2);
            }
            Alldiseases_combobox->Show();
            Disease_docname_textbox->Show();
            Disease_doc_phone_textbox->Show();
            Disease_info_textbox->Show();
            Disease_symps_listbox->Show();
            Disease_name_textbox->Show();
        }
        void view_Patients() {
            bool check = true;
            string choice;
            int viewChoice = -1;
            label29->Text = "Which Disease you want to display its Patients?";
            label29->Show();
            label28->Text = "";
            textBox4->Show();
            Alldiseases_combobox->Items->Clear();
            for (int i = 1; i <= allDiseases.size(); i++) {
                String^ str2 = gcnew String(allDiseases[i - 1].name.c_str());
                String^ index = gcnew String(to_string(i).c_str());
                /*if (i % 5 == 0 || i == allDiseases.size())
                    label28->Text += String::Format("{0}-{1}\n", index, str2);
                else
                    label28->Text += String::Format("{0}-{1}     ", index, str2);*/
                Alldiseases_combobox->Items->Add(str2);
            }
            Alldiseases_combobox->Show();
            Patients_of_chosen_disease_listbox->Show();
            //label28->Show();

        }
        void add_Symptom() {
            string choice;
            bool check = true;
            char choice_symptom = 'n';
            int iteration = 0;
            string symptom_info;
            //if the doctor doesn't have ant disease this if condition runs
            if ((*CurrentDoctor).doc_diseases.size() == 0) {
                label29->Text = "Unfortunately You haven't added any disease yet.";
                label29->Show();
                button4->Text = "End";
                textBox5->Hide();
                button6->Hide();
            }
            else {
                label29->Text = "Please choose Which disease you want\nto add its symptoms....";
                //This for loop is to display all diseases added by the doctor
                label28->Text = "";
                label29->Show();
                for (int i = 0; i < (*CurrentDoctor).doc_diseases.size(); i++) {
                    String^ index = gcnew String(to_string(i + 1).c_str());
                    String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[i].name.c_str());
                    if (i % 5 == 0 && i != 0)  label28->Text += String::Format("{0}-{1}\n", index, str2);
                    else label28->Text += String::Format("{0}-{1}     ", index, str2);
                }
                textBox5->Show();
                textBox5->Focus();
                button6->Show();
                label28->Show();
            } // end of else
        }
        void remove_disease() {
            string choice;
            bool check = true;
            //if the doctor doesn't have ant disease this if condition runs
            if ((*CurrentDoctor).doc_diseases.size() == 0) {
                label29->Text = "Unfortunately You haven't added any disease yet.\n";
                current_doctor_diseases_listbox->Hide();
                removed_diseases_listbox->Hide();
                add_disease_to_removed_button->Hide();
                remove_disease_from_removed_button->Hide();
                delete_diseases_button->Hide();
                clear_removed_diseases_button->Hide();
                remove_all_diseases_button->Hide();
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
                    current_doctor_diseases_listbox->Items->Add(str2);
                }
                button4->Text = "Next";
                 label28->Show();
                label29->Text = "Please choose Which disease you want to delete..";
                label29->Show();
                textBox5->Show();
                button6->Show();
                label28->Show();
                current_doctor_diseases_listbox->Show();
                removed_diseases_listbox->Show();
                add_disease_to_removed_button->Show();
                remove_disease_from_removed_button->Show();
                delete_diseases_button->Show();
                clear_removed_diseases_button->Show();
                remove_all_diseases_button->Show();
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
                Current_doc_diseases_combobox->Hide();
                removed_symps_listbox->Hide();
                current_disease_symps_listbox->Hide();
                add_symp_to_removed_button->Hide();
                remove_symp_from_removed_button->Hide();
                delete_symps_button->Hide();
                clear_remove_list_button->Hide();
                Remove_all_symps_button->Hide();
                textBox5->Hide();
                button6->Hide();
            }
            else {
                Current_doc_diseases_combobox->Show();
                removed_symps_listbox->Show();
                current_disease_symps_listbox->Show();
                add_symp_to_removed_button->Show();
                remove_symp_from_removed_button->Show();
                delete_symps_button->Show();
                clear_remove_list_button->Show();
                Remove_all_symps_button->Show();
                //panel6->BackColor = Color::FromArgb(100,0,0,0);
                //This for loop is to display all diseases added by the doctor
                label28->Text = "";
                for (int i = 0; i < (*CurrentDoctor).doc_diseases.size(); i++) {
                    String^ index = gcnew String(to_string(i + 1).c_str());
                    String^ str2 = gcnew String((*CurrentDoctor).doc_diseases[i].name.c_str());
                    Current_doc_diseases_combobox->Items->Add(str2);
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
            if (open) {
                open = false;
                pictureBox33->Hide();
                label20->Hide();
                label21->Hide();
                label35->Hide();
                pictureBox21->Hide();
                pictureBox20->Hide();
                pictureBox34->Hide();
                pictureBox35->Hide();
                pictureBox36->Hide();
            }
            if (open1) {
                open1 = false;
                label36->Hide();
                label37->Hide();
                label38->Hide();
                pictureBox38->Hide();
                pictureBox40->Hide();
                pictureBox41->Hide();
                pictureBox42->Hide();
                pictureBox39->Hide();
                pictureBox37->Hide();
            }
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
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->panel3 = (gcnew System::Windows::Forms::Panel());
            this->label13 = (gcnew System::Windows::Forms::Label());
            this->email_togglebutton = (gcnew Siticone::UI::WinForms::SiticoneWinToggleSwith());
            this->panel4 = (gcnew System::Windows::Forms::Panel());
            this->pictureBox37 = (gcnew System::Windows::Forms::PictureBox());
            this->label36 = (gcnew System::Windows::Forms::Label());
            this->pictureBox38 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox39 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox40 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox41 = (gcnew System::Windows::Forms::PictureBox());
            this->label37 = (gcnew System::Windows::Forms::Label());
            this->label38 = (gcnew System::Windows::Forms::Label());
            this->pictureBox42 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox43 = (gcnew System::Windows::Forms::PictureBox());
            this->button7 = (gcnew System::Windows::Forms::Button());
            this->Back_P = (gcnew System::Windows::Forms::Button());
            this->pictureBox12 = (gcnew System::Windows::Forms::PictureBox());
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
            this->label15 = (gcnew System::Windows::Forms::Label());
            this->pictureBox18 = (gcnew System::Windows::Forms::PictureBox());
            this->button9 = (gcnew System::Windows::Forms::Button());
            this->button8 = (gcnew System::Windows::Forms::Button());
            this->label34 = (gcnew System::Windows::Forms::Label());
            this->button5 = (gcnew System::Windows::Forms::Button());
            this->pictureBox31 = (gcnew System::Windows::Forms::PictureBox());
            this->label33 = (gcnew System::Windows::Forms::Label());
            this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
            this->panel5 = (gcnew System::Windows::Forms::Panel());
            this->Disease_doc_phone_textbox = (gcnew System::Windows::Forms::TextBox());
            this->Disease_docname_textbox = (gcnew System::Windows::Forms::TextBox());
            this->Disease_symps_listbox = (gcnew System::Windows::Forms::ListBox());
            this->Disease_info_textbox = (gcnew System::Windows::Forms::TextBox());
            this->Disease_name_textbox = (gcnew System::Windows::Forms::TextBox());
            this->Patients_of_chosen_disease_listbox = (gcnew System::Windows::Forms::ListBox());
            this->Alldiseases_combobox = (gcnew System::Windows::Forms::ComboBox());
            this->add_disease_to_removed_button = (gcnew System::Windows::Forms::Button());
            this->removed_diseases_listbox = (gcnew System::Windows::Forms::ListBox());
            this->remove_disease_from_removed_button = (gcnew System::Windows::Forms::Button());
            this->remove_all_diseases_button = (gcnew System::Windows::Forms::Button());
            this->clear_removed_diseases_button = (gcnew System::Windows::Forms::Button());
            this->delete_diseases_button = (gcnew System::Windows::Forms::Button());
            this->current_doctor_diseases_listbox = (gcnew System::Windows::Forms::ListBox());
            this->delete_symps_button = (gcnew System::Windows::Forms::Button());
            this->panel6 = (gcnew System::Windows::Forms::Panel());
            this->button10 = (gcnew System::Windows::Forms::Button());
            this->clear_remove_list_button = (gcnew System::Windows::Forms::Button());
            this->pictureBox36 = (gcnew System::Windows::Forms::PictureBox());
            this->Remove_all_symps_button = (gcnew System::Windows::Forms::Button());
            this->label35 = (gcnew System::Windows::Forms::Label());
            this->remove_symp_from_removed_button = (gcnew System::Windows::Forms::Button());
            this->add_symp_to_removed_button = (gcnew System::Windows::Forms::Button());
            this->pictureBox35 = (gcnew System::Windows::Forms::PictureBox());
            this->Current_doc_diseases_combobox = (gcnew System::Windows::Forms::ComboBox());
            this->pictureBox34 = (gcnew System::Windows::Forms::PictureBox());
            this->removed_symps_listbox = (gcnew System::Windows::Forms::ListBox());
            this->pictureBox21 = (gcnew System::Windows::Forms::PictureBox());
            this->current_disease_symps_listbox = (gcnew System::Windows::Forms::ListBox());
            this->pictureBox20 = (gcnew System::Windows::Forms::PictureBox());
            this->label21 = (gcnew System::Windows::Forms::Label());
            this->label20 = (gcnew System::Windows::Forms::Label());
            this->pictureBox33 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox32 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox30 = (gcnew System::Windows::Forms::PictureBox());
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
            this->textBox5 = (gcnew System::Windows::Forms::TextBox());
            this->label29 = (gcnew System::Windows::Forms::Label());
            this->label28 = (gcnew System::Windows::Forms::Label());
            this->pictureBox29 = (gcnew System::Windows::Forms::PictureBox());
            this->pictureBox28 = (gcnew System::Windows::Forms::PictureBox());
            this->label30 = (gcnew System::Windows::Forms::Label());
            this->pictureBox27 = (gcnew System::Windows::Forms::PictureBox());
            this->feed_panel = (gcnew System::Windows::Forms::Panel());
            this->Title_feed = (gcnew System::Windows::Forms::Label());
            this->back_feed_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Third_Most_name_label = (gcnew System::Windows::Forms::Label());
            this->Most_name_label = (gcnew System::Windows::Forms::Label());
            this->Second_Most_name_label = (gcnew System::Windows::Forms::Label());
            this->third_most_value = (gcnew System::Windows::Forms::Label());
            this->second_most_value = (gcnew System::Windows::Forms::Label());
            this->Most_value = (gcnew System::Windows::Forms::Label());
            this->second_most_front_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->third_most_front_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->most_front_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->third_most_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->second_most_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Most_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->x_axis_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->y_axis_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Recently_deleted_third_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Recently_deleted_second_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Recently_deleted_first_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Recently_added_third_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Recently_added_second_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Recently_added_first_picturebox = (gcnew System::Windows::Forms::PictureBox());
            this->Recently_deleted_third_label = (gcnew System::Windows::Forms::Label());
            this->Recently_deleted_second_label = (gcnew System::Windows::Forms::Label());
            this->Recently_deleted_first_label = (gcnew System::Windows::Forms::Label());
            this->Recently_added_third_label = (gcnew System::Windows::Forms::Label());
            this->Recently_added_second_label = (gcnew System::Windows::Forms::Label());
            this->Recently_added_first_label = (gcnew System::Windows::Forms::Label());
            this->Recently_deleted_label = (gcnew System::Windows::Forms::Label());
            this->Recently_added_label = (gcnew System::Windows::Forms::Label());
            this->feed_background = (gcnew System::Windows::Forms::PictureBox());
            this->feed_background_dark = (gcnew System::Windows::Forms::PictureBox());
            this->timer4 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer5 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer6 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer7 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer8 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer9 = (gcnew System::Windows::Forms::Timer(this->components));
            this->timer10 = (gcnew System::Windows::Forms::Timer(this->components));
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
            this->panel5->SuspendLayout();
            this->panel6->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->BeginInit();
            this->feed_panel->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_feed_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->second_most_front_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->third_most_front_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->most_front_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->third_most_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->second_most_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Most_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->x_axis_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->y_axis_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_deleted_third_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_deleted_second_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_deleted_first_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_added_third_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_added_second_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_added_first_picturebox))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed_background))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed_background_dark))->BeginInit();
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
            this->panel3->Controls->Add(this->label13);
            this->panel3->Controls->Add(this->email_togglebutton);
            this->panel3->Controls->Add(this->panel4);
            this->panel3->Controls->Add(this->button9);
            this->panel3->Controls->Add(this->button8);
            this->panel3->Controls->Add(this->label34);
            this->panel3->Controls->Add(this->button5);
            this->panel3->Controls->Add(this->pictureBox31);
            this->panel3->Controls->Add(this->label33);
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
            // label13
            // 
            this->label13->AutoSize = true;
            this->label13->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8));
            this->label13->ForeColor = System::Drawing::Color::White;
            this->label13->Location = System::Drawing::Point(1242, 431);
            this->label13->Name = L"label13";
            this->label13->Size = System::Drawing::Size(192, 38);
            this->label13->TabIndex = 58;
            this->label13->Text = L"Send email for each patient \r\ndiagnosed with your disease\? ";
            // 
            // email_togglebutton
            // 
            this->email_togglebutton->Location = System::Drawing::Point(1442, 440);
            this->email_togglebutton->Name = L"email_togglebutton";
            this->email_togglebutton->Size = System::Drawing::Size(45, 22);
            this->email_togglebutton->TabIndex = 57;
            this->email_togglebutton->Text = L"siticoneWinToggleSwith1";
            this->email_togglebutton->CheckedChanged += gcnew System::EventHandler(this, &MyForm::siticoneWinToggleSwith1_CheckedChanged_1);
            // 
            // panel4
            // 
            this->panel4->Controls->Add(this->pictureBox37);
            this->panel4->Controls->Add(this->label36);
            this->panel4->Controls->Add(this->pictureBox38);
            this->panel4->Controls->Add(this->pictureBox39);
            this->panel4->Controls->Add(this->pictureBox40);
            this->panel4->Controls->Add(this->pictureBox41);
            this->panel4->Controls->Add(this->label37);
            this->panel4->Controls->Add(this->label38);
            this->panel4->Controls->Add(this->pictureBox42);
            this->panel4->Controls->Add(this->pictureBox43);
            this->panel4->Controls->Add(this->button7);
            this->panel4->Controls->Add(this->Back_P);
            this->panel4->Controls->Add(this->pictureBox12);
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
            this->panel4->Controls->Add(this->label15);
            this->panel4->Controls->Add(this->pictureBox18);
            this->panel4->Location = System::Drawing::Point(3, 824);
            this->panel4->Name = L"panel4";
            this->panel4->Size = System::Drawing::Size(1896, 835);
            this->panel4->TabIndex = 50;
            // 
            // pictureBox37
            // 
            this->pictureBox37->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->pictureBox37->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox37.Image")));
            this->pictureBox37->Location = System::Drawing::Point(1184, 116);
            this->pictureBox37->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox37->Name = L"pictureBox37";
            this->pictureBox37->Size = System::Drawing::Size(99, 89);
            this->pictureBox37->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox37->TabIndex = 70;
            this->pictureBox37->TabStop = false;
            // 
            // label36
            // 
            this->label36->AutoSize = true;
            this->label36->BackColor = System::Drawing::Color::White;
            this->label36->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label36->ForeColor = System::Drawing::Color::Blue;
            this->label36->Location = System::Drawing::Point(1229, 253);
            this->label36->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label36->Name = L"label36";
            this->label36->Size = System::Drawing::Size(71, 23);
            this->label36->TabIndex = 69;
            this->label36->Text = L"Settings";
            // 
            // pictureBox38
            // 
            this->pictureBox38->BackColor = System::Drawing::Color::White;
            this->pictureBox38->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox38->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox38.Image")));
            this->pictureBox38->Location = System::Drawing::Point(1175, 238);
            this->pictureBox38->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox38->Name = L"pictureBox38";
            this->pictureBox38->Size = System::Drawing::Size(50, 50);
            this->pictureBox38->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox38->TabIndex = 68;
            this->pictureBox38->TabStop = false;
            this->pictureBox38->Click += gcnew System::EventHandler(this, &MyForm::pictureBox38_Click);
            // 
            // pictureBox39
            // 
            this->pictureBox39->BackColor = System::Drawing::Color::Blue;
            this->pictureBox39->Location = System::Drawing::Point(1144, 215);
            this->pictureBox39->Name = L"pictureBox39";
            this->pictureBox39->Size = System::Drawing::Size(187, 3);
            this->pictureBox39->TabIndex = 67;
            this->pictureBox39->TabStop = false;
            // 
            // pictureBox40
            // 
            this->pictureBox40->BackColor = System::Drawing::Color::White;
            this->pictureBox40->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox40->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox40.Image")));
            this->pictureBox40->Location = System::Drawing::Point(1175, 347);
            this->pictureBox40->Name = L"pictureBox40";
            this->pictureBox40->Size = System::Drawing::Size(50, 50);
            this->pictureBox40->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox40->TabIndex = 64;
            this->pictureBox40->TabStop = false;
            this->pictureBox40->Click += gcnew System::EventHandler(this, &MyForm::pictureBox40_Click);
            // 
            // pictureBox41
            // 
            this->pictureBox41->BackColor = System::Drawing::Color::White;
            this->pictureBox41->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox41->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox41.Image")));
            this->pictureBox41->Location = System::Drawing::Point(1170, 291);
            this->pictureBox41->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox41->Name = L"pictureBox41";
            this->pictureBox41->Size = System::Drawing::Size(60, 62);
            this->pictureBox41->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox41->TabIndex = 63;
            this->pictureBox41->TabStop = false;
            this->pictureBox41->Click += gcnew System::EventHandler(this, &MyForm::pictureBox41_Click);
            // 
            // label37
            // 
            this->label37->AutoSize = true;
            this->label37->BackColor = System::Drawing::Color::White;
            this->label37->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label37->ForeColor = System::Drawing::Color::Blue;
            this->label37->Location = System::Drawing::Point(1229, 355);
            this->label37->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label37->Name = L"label37";
            this->label37->Size = System::Drawing::Size(43, 23);
            this->label37->TabIndex = 61;
            this->label37->Text = L"Quit";
            // 
            // label38
            // 
            this->label38->AutoSize = true;
            this->label38->BackColor = System::Drawing::Color::White;
            this->label38->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label38->ForeColor = System::Drawing::Color::Blue;
            this->label38->Location = System::Drawing::Point(1229, 307);
            this->label38->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label38->Name = L"label38";
            this->label38->Size = System::Drawing::Size(64, 23);
            this->label38->TabIndex = 62;
            this->label38->Text = L"Logout";
            // 
            // pictureBox42
            // 
            this->pictureBox42->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox42->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->pictureBox42->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox42.Image")));
            this->pictureBox42->Location = System::Drawing::Point(1110, 69);
            this->pictureBox42->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox42->Name = L"pictureBox42";
            this->pictureBox42->Size = System::Drawing::Size(253, 342);
            this->pictureBox42->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox42->TabIndex = 66;
            this->pictureBox42->TabStop = false;
            // 
            // pictureBox43
            // 
            this->pictureBox43->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox43->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox43.Image")));
            this->pictureBox43->Location = System::Drawing::Point(1197, 2);
            this->pictureBox43->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox43->Name = L"pictureBox43";
            this->pictureBox43->Size = System::Drawing::Size(71, 66);
            this->pictureBox43->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox43->TabIndex = 65;
            this->pictureBox43->TabStop = false;
            this->pictureBox43->Click += gcnew System::EventHandler(this, &MyForm::pictureBox43_Click);
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
            this->pictureBox10->Click += gcnew System::EventHandler(this, &MyForm::pictureBox10_Click);
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
            // pictureBox31
            // 
            this->pictureBox31->Location = System::Drawing::Point(732, 52);
            this->pictureBox31->Name = L"pictureBox31";
            this->pictureBox31->Size = System::Drawing::Size(379, 326);
            this->pictureBox31->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox31->TabIndex = 53;
            this->pictureBox31->TabStop = false;
            this->pictureBox31->Click += gcnew System::EventHandler(this, &MyForm::pictureBox31_Click);
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
            // panel5
            // 
            this->panel5->Controls->Add(this->Disease_doc_phone_textbox);
            this->panel5->Controls->Add(this->Disease_docname_textbox);
            this->panel5->Controls->Add(this->Disease_symps_listbox);
            this->panel5->Controls->Add(this->Disease_info_textbox);
            this->panel5->Controls->Add(this->Disease_name_textbox);
            this->panel5->Controls->Add(this->Patients_of_chosen_disease_listbox);
            this->panel5->Controls->Add(this->Alldiseases_combobox);
            this->panel5->Controls->Add(this->add_disease_to_removed_button);
            this->panel5->Controls->Add(this->removed_diseases_listbox);
            this->panel5->Controls->Add(this->remove_disease_from_removed_button);
            this->panel5->Controls->Add(this->remove_all_diseases_button);
            this->panel5->Controls->Add(this->clear_removed_diseases_button);
            this->panel5->Controls->Add(this->delete_diseases_button);
            this->panel5->Controls->Add(this->current_doctor_diseases_listbox);
            this->panel5->Controls->Add(this->delete_symps_button);
            this->panel5->Controls->Add(this->panel6);
            this->panel5->Controls->Add(this->clear_remove_list_button);
            this->panel5->Controls->Add(this->pictureBox36);
            this->panel5->Controls->Add(this->Remove_all_symps_button);
            this->panel5->Controls->Add(this->label35);
            this->panel5->Controls->Add(this->remove_symp_from_removed_button);
            this->panel5->Controls->Add(this->add_symp_to_removed_button);
            this->panel5->Controls->Add(this->pictureBox35);
            this->panel5->Controls->Add(this->Current_doc_diseases_combobox);
            this->panel5->Controls->Add(this->pictureBox34);
            this->panel5->Controls->Add(this->removed_symps_listbox);
            this->panel5->Controls->Add(this->pictureBox21);
            this->panel5->Controls->Add(this->current_disease_symps_listbox);
            this->panel5->Controls->Add(this->pictureBox20);
            this->panel5->Controls->Add(this->label21);
            this->panel5->Controls->Add(this->label20);
            this->panel5->Controls->Add(this->pictureBox33);
            this->panel5->Controls->Add(this->pictureBox32);
            this->panel5->Controls->Add(this->pictureBox30);
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
            this->panel5->Controls->Add(this->textBox5);
            this->panel5->Controls->Add(this->label29);
            this->panel5->Controls->Add(this->label28);
            this->panel5->Controls->Add(this->pictureBox29);
            this->panel5->Controls->Add(this->pictureBox28);
            this->panel5->Controls->Add(this->label30);
            this->panel5->Controls->Add(this->pictureBox27);
            this->panel5->Controls->Add(this->feed_panel);
            this->panel5->Location = System::Drawing::Point(1, -2);
            this->panel5->Name = L"panel5";
            this->panel5->Size = System::Drawing::Size(1896, 735);
            this->panel5->TabIndex = 48;
            this->panel5->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::panel5_Paint);
            // 
            // Disease_doc_phone_textbox
            // 
            this->Disease_doc_phone_textbox->Location = System::Drawing::Point(735, 568);
            this->Disease_doc_phone_textbox->Name = L"Disease_doc_phone_textbox";
            this->Disease_doc_phone_textbox->ReadOnly = true;
            this->Disease_doc_phone_textbox->Size = System::Drawing::Size(169, 24);
            this->Disease_doc_phone_textbox->TabIndex = 77;
            // 
            // Disease_docname_textbox
            // 
            this->Disease_docname_textbox->Location = System::Drawing::Point(733, 522);
            this->Disease_docname_textbox->Name = L"Disease_docname_textbox";
            this->Disease_docname_textbox->ReadOnly = true;
            this->Disease_docname_textbox->Size = System::Drawing::Size(169, 24);
            this->Disease_docname_textbox->TabIndex = 76;
            // 
            // Disease_symps_listbox
            // 
            this->Disease_symps_listbox->FormattingEnabled = true;
            this->Disease_symps_listbox->ItemHeight = 16;
            this->Disease_symps_listbox->Location = System::Drawing::Point(733, 380);
            this->Disease_symps_listbox->Name = L"Disease_symps_listbox";
            this->Disease_symps_listbox->Size = System::Drawing::Size(171, 132);
            this->Disease_symps_listbox->TabIndex = 75;
            // 
            // Disease_info_textbox
            // 
            this->Disease_info_textbox->Location = System::Drawing::Point(733, 268);
            this->Disease_info_textbox->Multiline = true;
            this->Disease_info_textbox->Name = L"Disease_info_textbox";
            this->Disease_info_textbox->ReadOnly = true;
            this->Disease_info_textbox->Size = System::Drawing::Size(169, 100);
            this->Disease_info_textbox->TabIndex = 74;
            // 
            // Disease_name_textbox
            // 
            this->Disease_name_textbox->Location = System::Drawing::Point(733, 227);
            this->Disease_name_textbox->Name = L"Disease_name_textbox";
            this->Disease_name_textbox->ReadOnly = true;
            this->Disease_name_textbox->Size = System::Drawing::Size(169, 24);
            this->Disease_name_textbox->TabIndex = 73;
            // 
            // Patients_of_chosen_disease_listbox
            // 
            this->Patients_of_chosen_disease_listbox->FormattingEnabled = true;
            this->Patients_of_chosen_disease_listbox->ItemHeight = 16;
            this->Patients_of_chosen_disease_listbox->Location = System::Drawing::Point(694, 196);
            this->Patients_of_chosen_disease_listbox->Name = L"Patients_of_chosen_disease_listbox";
            this->Patients_of_chosen_disease_listbox->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
            this->Patients_of_chosen_disease_listbox->Size = System::Drawing::Size(251, 276);
            this->Patients_of_chosen_disease_listbox->TabIndex = 72;
            // 
            // Alldiseases_combobox
            // 
            this->Alldiseases_combobox->FormattingEnabled = true;
            this->Alldiseases_combobox->Location = System::Drawing::Point(375, 145);
            this->Alldiseases_combobox->Name = L"Alldiseases_combobox";
            this->Alldiseases_combobox->Size = System::Drawing::Size(106, 24);
            this->Alldiseases_combobox->TabIndex = 71;
            this->Alldiseases_combobox->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::Alldiseases_combobox_SelectedValueChanged);
            // 
            // add_disease_to_removed_button
            // 
            this->add_disease_to_removed_button->Location = System::Drawing::Point(618, 225);
            this->add_disease_to_removed_button->Name = L"add_disease_to_removed_button";
            this->add_disease_to_removed_button->Size = System::Drawing::Size(66, 23);
            this->add_disease_to_removed_button->TabIndex = 66;
            this->add_disease_to_removed_button->Text = L"Add";
            this->add_disease_to_removed_button->UseVisualStyleBackColor = true;
            this->add_disease_to_removed_button->Click += gcnew System::EventHandler(this, &MyForm::add_disease_to_removed_button_Click);
            // 
            // removed_diseases_listbox
            // 
            this->removed_diseases_listbox->FormattingEnabled = true;
            this->removed_diseases_listbox->ItemHeight = 16;
            this->removed_diseases_listbox->Location = System::Drawing::Point(694, 196);
            this->removed_diseases_listbox->Name = L"removed_diseases_listbox";
            this->removed_diseases_listbox->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
            this->removed_diseases_listbox->Size = System::Drawing::Size(251, 276);
            this->removed_diseases_listbox->TabIndex = 65;
            // 
            // remove_disease_from_removed_button
            // 
            this->remove_disease_from_removed_button->Location = System::Drawing::Point(618, 330);
            this->remove_disease_from_removed_button->Name = L"remove_disease_from_removed_button";
            this->remove_disease_from_removed_button->Size = System::Drawing::Size(66, 23);
            this->remove_disease_from_removed_button->TabIndex = 67;
            this->remove_disease_from_removed_button->Text = L"remove";
            this->remove_disease_from_removed_button->UseVisualStyleBackColor = true;
            this->remove_disease_from_removed_button->Click += gcnew System::EventHandler(this, &MyForm::remove_all_diseases_button_Click);
            // 
            // remove_all_diseases_button
            // 
            this->remove_all_diseases_button->Location = System::Drawing::Point(410, 490);
            this->remove_all_diseases_button->Name = L"remove_all_diseases_button";
            this->remove_all_diseases_button->Size = System::Drawing::Size(147, 23);
            this->remove_all_diseases_button->TabIndex = 68;
            this->remove_all_diseases_button->Text = L"Remove all diseases";
            this->remove_all_diseases_button->UseVisualStyleBackColor = true;
            this->remove_all_diseases_button->Click += gcnew System::EventHandler(this, &MyForm::remove_all_diseases_button_Click);
            // 
            // clear_removed_diseases_button
            // 
            this->clear_removed_diseases_button->Location = System::Drawing::Point(742, 498);
            this->clear_removed_diseases_button->Name = L"clear_removed_diseases_button";
            this->clear_removed_diseases_button->Size = System::Drawing::Size(147, 23);
            this->clear_removed_diseases_button->TabIndex = 69;
            this->clear_removed_diseases_button->Text = L"Clear list";
            this->clear_removed_diseases_button->UseVisualStyleBackColor = true;
            this->clear_removed_diseases_button->Click += gcnew System::EventHandler(this, &MyForm::clear_removed_diseases_button_Click);
            // 
            // delete_diseases_button
            // 
            this->delete_diseases_button->Location = System::Drawing::Point(975, 146);
            this->delete_diseases_button->Name = L"delete_diseases_button";
            this->delete_diseases_button->Size = System::Drawing::Size(66, 23);
            this->delete_diseases_button->TabIndex = 70;
            this->delete_diseases_button->Text = L"Delete";
            this->delete_diseases_button->UseVisualStyleBackColor = true;
            this->delete_diseases_button->Click += gcnew System::EventHandler(this, &MyForm::delete_diseases_button_Click);
            // 
            // current_doctor_diseases_listbox
            // 
            this->current_doctor_diseases_listbox->FormattingEnabled = true;
            this->current_doctor_diseases_listbox->ItemHeight = 16;
            this->current_doctor_diseases_listbox->Location = System::Drawing::Point(360, 196);
            this->current_doctor_diseases_listbox->Name = L"current_doctor_diseases_listbox";
            this->current_doctor_diseases_listbox->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
            this->current_doctor_diseases_listbox->Size = System::Drawing::Size(251, 276);
            this->current_doctor_diseases_listbox->TabIndex = 64;
            // 
            // delete_symps_button
            // 
            this->delete_symps_button->Location = System::Drawing::Point(977, 146);
            this->delete_symps_button->Name = L"delete_symps_button";
            this->delete_symps_button->Size = System::Drawing::Size(66, 23);
            this->delete_symps_button->TabIndex = 15;
            this->delete_symps_button->Text = L"Delete";
            this->delete_symps_button->UseVisualStyleBackColor = true;
            this->delete_symps_button->Click += gcnew System::EventHandler(this, &MyForm::delete_symps_button_Click);
            // 
            // panel6
            // 
            this->panel6->BackColor = System::Drawing::Color::Transparent;
            this->panel6->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->panel6->Controls->Add(this->button10);
            this->panel6->Location = System::Drawing::Point(794, 697);
            this->panel6->Name = L"panel6";
            this->panel6->Size = System::Drawing::Size(175, 100);
            this->panel6->TabIndex = 63;
            // 
            // button10
            // 
            this->button10->Location = System::Drawing::Point(44, 38);
            this->button10->Name = L"button10";
            this->button10->Size = System::Drawing::Size(66, 23);
            this->button10->TabIndex = 4;
            this->button10->Text = L"Add";
            this->button10->UseVisualStyleBackColor = true;
            // 
            // clear_remove_list_button
            // 
            this->clear_remove_list_button->Location = System::Drawing::Point(742, 496);
            this->clear_remove_list_button->Name = L"clear_remove_list_button";
            this->clear_remove_list_button->Size = System::Drawing::Size(147, 23);
            this->clear_remove_list_button->TabIndex = 14;
            this->clear_remove_list_button->Text = L"Clear list";
            this->clear_remove_list_button->UseVisualStyleBackColor = true;
            this->clear_remove_list_button->Click += gcnew System::EventHandler(this, &MyForm::clear_remove_list_button_Click);
            // 
            // pictureBox36
            // 
            this->pictureBox36->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->pictureBox36->Location = System::Drawing::Point(1169, 118);
            this->pictureBox36->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox36->Name = L"pictureBox36";
            this->pictureBox36->Size = System::Drawing::Size(99, 89);
            this->pictureBox36->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox36->TabIndex = 60;
            this->pictureBox36->TabStop = false;
            // 
            // Remove_all_symps_button
            // 
            this->Remove_all_symps_button->Location = System::Drawing::Point(410, 491);
            this->Remove_all_symps_button->Name = L"Remove_all_symps_button";
            this->Remove_all_symps_button->Size = System::Drawing::Size(147, 23);
            this->Remove_all_symps_button->TabIndex = 13;
            this->Remove_all_symps_button->Text = L"Remove all symps";
            this->Remove_all_symps_button->UseVisualStyleBackColor = true;
            // 
            // label35
            // 
            this->label35->AutoSize = true;
            this->label35->BackColor = System::Drawing::Color::White;
            this->label35->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label35->ForeColor = System::Drawing::Color::Blue;
            this->label35->Location = System::Drawing::Point(1212, 255);
            this->label35->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label35->Name = L"label35";
            this->label35->Size = System::Drawing::Size(71, 23);
            this->label35->TabIndex = 59;
            this->label35->Text = L"Settings";
            // 
            // remove_symp_from_removed_button
            // 
            this->remove_symp_from_removed_button->Location = System::Drawing::Point(618, 330);
            this->remove_symp_from_removed_button->Name = L"remove_symp_from_removed_button";
            this->remove_symp_from_removed_button->Size = System::Drawing::Size(66, 23);
            this->remove_symp_from_removed_button->TabIndex = 12;
            this->remove_symp_from_removed_button->Text = L"remove";
            this->remove_symp_from_removed_button->UseVisualStyleBackColor = true;
            // 
            // add_symp_to_removed_button
            // 
            this->add_symp_to_removed_button->Location = System::Drawing::Point(618, 225);
            this->add_symp_to_removed_button->Name = L"add_symp_to_removed_button";
            this->add_symp_to_removed_button->Size = System::Drawing::Size(66, 23);
            this->add_symp_to_removed_button->TabIndex = 11;
            this->add_symp_to_removed_button->Text = L"Add";
            this->add_symp_to_removed_button->UseVisualStyleBackColor = true;
            this->add_symp_to_removed_button->Click += gcnew System::EventHandler(this, &MyForm::add_symp_to_removed_button_Click);
            // 
            // pictureBox35
            // 
            this->pictureBox35->BackColor = System::Drawing::Color::White;
            this->pictureBox35->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox35->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox35.Image")));
            this->pictureBox35->Location = System::Drawing::Point(1158, 240);
            this->pictureBox35->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox35->Name = L"pictureBox35";
            this->pictureBox35->Size = System::Drawing::Size(50, 50);
            this->pictureBox35->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox35->TabIndex = 58;
            this->pictureBox35->TabStop = false;
            this->pictureBox35->Click += gcnew System::EventHandler(this, &MyForm::pictureBox35_Click);
            // 
            // Current_doc_diseases_combobox
            // 
            this->Current_doc_diseases_combobox->FormattingEnabled = true;
            this->Current_doc_diseases_combobox->Location = System::Drawing::Point(598, 146);
            this->Current_doc_diseases_combobox->Name = L"Current_doc_diseases_combobox";
            this->Current_doc_diseases_combobox->Size = System::Drawing::Size(106, 24);
            this->Current_doc_diseases_combobox->TabIndex = 10;
            this->Current_doc_diseases_combobox->SelectedValueChanged += gcnew System::EventHandler(this, &MyForm::Current_doc_diseases_combobox_SelectedValueChanged);
            // 
            // pictureBox34
            // 
            this->pictureBox34->BackColor = System::Drawing::Color::Blue;
            this->pictureBox34->Location = System::Drawing::Point(1129, 217);
            this->pictureBox34->Name = L"pictureBox34";
            this->pictureBox34->Size = System::Drawing::Size(187, 3);
            this->pictureBox34->TabIndex = 57;
            this->pictureBox34->TabStop = false;
            // 
            // removed_symps_listbox
            // 
            this->removed_symps_listbox->FormattingEnabled = true;
            this->removed_symps_listbox->ItemHeight = 16;
            this->removed_symps_listbox->Location = System::Drawing::Point(694, 195);
            this->removed_symps_listbox->Name = L"removed_symps_listbox";
            this->removed_symps_listbox->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
            this->removed_symps_listbox->Size = System::Drawing::Size(251, 276);
            this->removed_symps_listbox->TabIndex = 9;
            this->removed_symps_listbox->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::removed_symps_listbox_SelectedIndexChanged);
            // 
            // pictureBox21
            // 
            this->pictureBox21->BackColor = System::Drawing::Color::White;
            this->pictureBox21->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox21->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox21.Image")));
            this->pictureBox21->Location = System::Drawing::Point(1158, 349);
            this->pictureBox21->Name = L"pictureBox21";
            this->pictureBox21->Size = System::Drawing::Size(50, 50);
            this->pictureBox21->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox21->TabIndex = 46;
            this->pictureBox21->TabStop = false;
            this->pictureBox21->Click += gcnew System::EventHandler(this, &MyForm::pictureBox21_Click_1);
            // 
            // current_disease_symps_listbox
            // 
            this->current_disease_symps_listbox->FormattingEnabled = true;
            this->current_disease_symps_listbox->ItemHeight = 16;
            this->current_disease_symps_listbox->Location = System::Drawing::Point(362, 195);
            this->current_disease_symps_listbox->Name = L"current_disease_symps_listbox";
            this->current_disease_symps_listbox->SelectionMode = System::Windows::Forms::SelectionMode::MultiSimple;
            this->current_disease_symps_listbox->Size = System::Drawing::Size(251, 276);
            this->current_disease_symps_listbox->TabIndex = 8;
            // 
            // pictureBox20
            // 
            this->pictureBox20->BackColor = System::Drawing::Color::White;
            this->pictureBox20->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox20->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox20.Image")));
            this->pictureBox20->Location = System::Drawing::Point(1153, 293);
            this->pictureBox20->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox20->Name = L"pictureBox20";
            this->pictureBox20->Size = System::Drawing::Size(60, 62);
            this->pictureBox20->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox20->TabIndex = 38;
            this->pictureBox20->TabStop = false;
            this->pictureBox20->Click += gcnew System::EventHandler(this, &MyForm::pictureBox20_Click);
            // 
            // label21
            // 
            this->label21->AutoSize = true;
            this->label21->BackColor = System::Drawing::Color::White;
            this->label21->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label21->ForeColor = System::Drawing::Color::Blue;
            this->label21->Location = System::Drawing::Point(1212, 357);
            this->label21->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label21->Name = L"label21";
            this->label21->Size = System::Drawing::Size(43, 23);
            this->label21->TabIndex = 31;
            this->label21->Text = L"Quit";
            // 
            // label20
            // 
            this->label20->AutoSize = true;
            this->label20->BackColor = System::Drawing::Color::White;
            this->label20->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->label20->ForeColor = System::Drawing::Color::Blue;
            this->label20->Location = System::Drawing::Point(1212, 309);
            this->label20->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
            this->label20->Name = L"label20";
            this->label20->Size = System::Drawing::Size(64, 23);
            this->label20->TabIndex = 32;
            this->label20->Text = L"Logout";
            // 
            // pictureBox33
            // 
            this->pictureBox33->BackColor = System::Drawing::Color::Transparent;
            this->pictureBox33->Cursor = System::Windows::Forms::Cursors::Arrow;
            this->pictureBox33->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox33.Image")));
            this->pictureBox33->Location = System::Drawing::Point(1096, 77);
            this->pictureBox33->Margin = System::Windows::Forms::Padding(2);
            this->pictureBox33->Name = L"pictureBox33";
            this->pictureBox33->Size = System::Drawing::Size(253, 342);
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
            this->pictureBox30->Cursor = System::Windows::Forms::Cursors::Hand;
            this->pictureBox30->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox30.Image")));
            this->pictureBox30->Location = System::Drawing::Point(585, 271);
            this->pictureBox30->Name = L"pictureBox30";
            this->pictureBox30->Size = System::Drawing::Size(179, 142);
            this->pictureBox30->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->pictureBox30->TabIndex = 53;
            this->pictureBox30->TabStop = false;
            this->pictureBox30->Click += gcnew System::EventHandler(this, &MyForm::pictureBox30_Click);
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
            this->textBox6->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox6_KeyDown);
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
            // textBox5
            // 
            this->textBox5->Location = System::Drawing::Point(89, 552);
            this->textBox5->Name = L"textBox5";
            this->textBox5->Size = System::Drawing::Size(207, 24);
            this->textBox5->TabIndex = 45;
            this->textBox5->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::textBox5_KeyDown);
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
            // feed_panel
            // 
            this->feed_panel->Controls->Add(this->Title_feed);
            this->feed_panel->Controls->Add(this->back_feed_picturebox);
            this->feed_panel->Controls->Add(this->Third_Most_name_label);
            this->feed_panel->Controls->Add(this->Most_name_label);
            this->feed_panel->Controls->Add(this->Second_Most_name_label);
            this->feed_panel->Controls->Add(this->third_most_value);
            this->feed_panel->Controls->Add(this->second_most_value);
            this->feed_panel->Controls->Add(this->Most_value);
            this->feed_panel->Controls->Add(this->second_most_front_picturebox);
            this->feed_panel->Controls->Add(this->third_most_front_picturebox);
            this->feed_panel->Controls->Add(this->most_front_picturebox);
            this->feed_panel->Controls->Add(this->third_most_picturebox);
            this->feed_panel->Controls->Add(this->second_most_picturebox);
            this->feed_panel->Controls->Add(this->Most_picturebox);
            this->feed_panel->Controls->Add(this->x_axis_picturebox);
            this->feed_panel->Controls->Add(this->y_axis_picturebox);
            this->feed_panel->Controls->Add(this->Recently_deleted_third_picturebox);
            this->feed_panel->Controls->Add(this->Recently_deleted_second_picturebox);
            this->feed_panel->Controls->Add(this->Recently_deleted_first_picturebox);
            this->feed_panel->Controls->Add(this->Recently_added_third_picturebox);
            this->feed_panel->Controls->Add(this->Recently_added_second_picturebox);
            this->feed_panel->Controls->Add(this->Recently_added_first_picturebox);
            this->feed_panel->Controls->Add(this->Recently_deleted_third_label);
            this->feed_panel->Controls->Add(this->Recently_deleted_second_label);
            this->feed_panel->Controls->Add(this->Recently_deleted_first_label);
            this->feed_panel->Controls->Add(this->Recently_added_third_label);
            this->feed_panel->Controls->Add(this->Recently_added_second_label);
            this->feed_panel->Controls->Add(this->Recently_added_first_label);
            this->feed_panel->Controls->Add(this->Recently_deleted_label);
            this->feed_panel->Controls->Add(this->Recently_added_label);
            this->feed_panel->Controls->Add(this->feed_background);
            this->feed_panel->Controls->Add(this->feed_background_dark);
            this->feed_panel->Location = System::Drawing::Point(0, 4);
            this->feed_panel->Name = L"feed_panel";
            this->feed_panel->Size = System::Drawing::Size(1352, 834);
            this->feed_panel->TabIndex = 78;
            this->feed_panel->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &MyForm::feed_panel_Paint);
            // 
            // Title_feed
            // 
            this->Title_feed->AutoSize = true;
            this->Title_feed->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 20));
            this->Title_feed->ForeColor = System::Drawing::Color::White;
            this->Title_feed->Location = System::Drawing::Point(418, 11);
            this->Title_feed->Name = L"Title_feed";
            this->Title_feed->Size = System::Drawing::Size(412, 46);
            this->Title_feed->TabIndex = 52;
            this->Title_feed->Text = L"Most Diseases Diagnosed";
            // 
            // back_feed_picturebox
            // 
            this->back_feed_picturebox->Cursor = System::Windows::Forms::Cursors::Hand;
            this->back_feed_picturebox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"back_feed_picturebox.Image")));
            this->back_feed_picturebox->Location = System::Drawing::Point(11, 11);
            this->back_feed_picturebox->Name = L"back_feed_picturebox";
            this->back_feed_picturebox->Size = System::Drawing::Size(67, 60);
            this->back_feed_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->back_feed_picturebox->TabIndex = 51;
            this->back_feed_picturebox->TabStop = false;
            this->back_feed_picturebox->Click += gcnew System::EventHandler(this, &MyForm::back_feed_picturebox_Click);
            // 
            // Third_Most_name_label
            // 
            this->Third_Most_name_label->AutoSize = true;
            this->Third_Most_name_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Third_Most_name_label->ForeColor = System::Drawing::Color::White;
            this->Third_Most_name_label->Location = System::Drawing::Point(764, 601);
            this->Third_Most_name_label->Name = L"Third_Most_name_label";
            this->Third_Most_name_label->Size = System::Drawing::Size(53, 19);
            this->Third_Most_name_label->TabIndex = 50;
            this->Third_Most_name_label->Text = L"label13";
            // 
            // Most_name_label
            // 
            this->Most_name_label->AutoSize = true;
            this->Most_name_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Most_name_label->ForeColor = System::Drawing::Color::White;
            this->Most_name_label->Location = System::Drawing::Point(614, 600);
            this->Most_name_label->Name = L"Most_name_label";
            this->Most_name_label->Size = System::Drawing::Size(53, 19);
            this->Most_name_label->TabIndex = 49;
            this->Most_name_label->Text = L"label13";
            // 
            // Second_Most_name_label
            // 
            this->Second_Most_name_label->AutoSize = true;
            this->Second_Most_name_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Second_Most_name_label->ForeColor = System::Drawing::Color::White;
            this->Second_Most_name_label->Location = System::Drawing::Point(461, 599);
            this->Second_Most_name_label->Name = L"Second_Most_name_label";
            this->Second_Most_name_label->Size = System::Drawing::Size(53, 19);
            this->Second_Most_name_label->TabIndex = 48;
            this->Second_Most_name_label->Text = L"label13";
            // 
            // third_most_value
            // 
            this->third_most_value->AutoSize = true;
            this->third_most_value->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9));
            this->third_most_value->ForeColor = System::Drawing::Color::White;
            this->third_most_value->Location = System::Drawing::Point(299, 369);
            this->third_most_value->Name = L"third_most_value";
            this->third_most_value->Size = System::Drawing::Size(56, 20);
            this->third_most_value->TabIndex = 47;
            this->third_most_value->Text = L"label13";
            // 
            // second_most_value
            // 
            this->second_most_value->AutoSize = true;
            this->second_most_value->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 9));
            this->second_most_value->ForeColor = System::Drawing::Color::White;
            this->second_most_value->Location = System::Drawing::Point(299, 285);
            this->second_most_value->Name = L"second_most_value";
            this->second_most_value->Size = System::Drawing::Size(56, 20);
            this->second_most_value->TabIndex = 46;
            this->second_most_value->Text = L"label13";
            // 
            // Most_value
            // 
            this->Most_value->AutoSize = true;
            this->Most_value->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11));
            this->Most_value->ForeColor = System::Drawing::Color::White;
            this->Most_value->Location = System::Drawing::Point(299, 132);
            this->Most_value->Name = L"Most_value";
            this->Most_value->Size = System::Drawing::Size(72, 25);
            this->Most_value->TabIndex = 45;
            this->Most_value->Text = L"label13";
            // 
            // second_most_front_picturebox
            // 
            this->second_most_front_picturebox->Location = System::Drawing::Point(465, 287);
            this->second_most_front_picturebox->Name = L"second_most_front_picturebox";
            this->second_most_front_picturebox->Size = System::Drawing::Size(46, 294);
            this->second_most_front_picturebox->TabIndex = 44;
            this->second_most_front_picturebox->TabStop = false;
            // 
            // third_most_front_picturebox
            // 
            this->third_most_front_picturebox->Location = System::Drawing::Point(767, 368);
            this->third_most_front_picturebox->Name = L"third_most_front_picturebox";
            this->third_most_front_picturebox->Size = System::Drawing::Size(46, 214);
            this->third_most_front_picturebox->TabIndex = 43;
            this->third_most_front_picturebox->TabStop = false;
            // 
            // most_front_picturebox
            // 
            this->most_front_picturebox->Location = System::Drawing::Point(618, 133);
            this->most_front_picturebox->Name = L"most_front_picturebox";
            this->most_front_picturebox->Size = System::Drawing::Size(46, 449);
            this->most_front_picturebox->TabIndex = 42;
            this->most_front_picturebox->TabStop = false;
            // 
            // third_most_picturebox
            // 
            this->third_most_picturebox->BackColor = System::Drawing::Color::White;
            this->third_most_picturebox->Location = System::Drawing::Point(767, 377);
            this->third_most_picturebox->Name = L"third_most_picturebox";
            this->third_most_picturebox->Size = System::Drawing::Size(46, 206);
            this->third_most_picturebox->TabIndex = 40;
            this->third_most_picturebox->TabStop = false;
            // 
            // second_most_picturebox
            // 
            this->second_most_picturebox->BackColor = System::Drawing::Color::White;
            this->second_most_picturebox->Location = System::Drawing::Point(465, 288);
            this->second_most_picturebox->Name = L"second_most_picturebox";
            this->second_most_picturebox->Size = System::Drawing::Size(46, 293);
            this->second_most_picturebox->TabIndex = 39;
            this->second_most_picturebox->TabStop = false;
            // 
            // Most_picturebox
            // 
            this->Most_picturebox->BackColor = System::Drawing::Color::White;
            this->Most_picturebox->Location = System::Drawing::Point(618, 142);
            this->Most_picturebox->Name = L"Most_picturebox";
            this->Most_picturebox->Size = System::Drawing::Size(46, 441);
            this->Most_picturebox->TabIndex = 38;
            this->Most_picturebox->TabStop = false;
            // 
            // x_axis_picturebox
            // 
            this->x_axis_picturebox->BackColor = System::Drawing::Color::White;
            this->x_axis_picturebox->Location = System::Drawing::Point(352, 578);
            this->x_axis_picturebox->Name = L"x_axis_picturebox";
            this->x_axis_picturebox->Size = System::Drawing::Size(10, 5);
            this->x_axis_picturebox->TabIndex = 37;
            this->x_axis_picturebox->TabStop = false;
            // 
            // y_axis_picturebox
            // 
            this->y_axis_picturebox->BackColor = System::Drawing::Color::White;
            this->y_axis_picturebox->Location = System::Drawing::Point(352, 76);
            this->y_axis_picturebox->Name = L"y_axis_picturebox";
            this->y_axis_picturebox->Size = System::Drawing::Size(6, 11);
            this->y_axis_picturebox->TabIndex = 36;
            this->y_axis_picturebox->TabStop = false;
            // 
            // Recently_deleted_third_picturebox
            // 
            this->Recently_deleted_third_picturebox->Location = System::Drawing::Point(1092, 402);
            this->Recently_deleted_third_picturebox->Name = L"Recently_deleted_third_picturebox";
            this->Recently_deleted_third_picturebox->Size = System::Drawing::Size(75, 68);
            this->Recently_deleted_third_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->Recently_deleted_third_picturebox->TabIndex = 35;
            this->Recently_deleted_third_picturebox->TabStop = false;
            // 
            // Recently_deleted_second_picturebox
            // 
            this->Recently_deleted_second_picturebox->Location = System::Drawing::Point(1092, 285);
            this->Recently_deleted_second_picturebox->Name = L"Recently_deleted_second_picturebox";
            this->Recently_deleted_second_picturebox->Size = System::Drawing::Size(75, 68);
            this->Recently_deleted_second_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->Recently_deleted_second_picturebox->TabIndex = 34;
            this->Recently_deleted_second_picturebox->TabStop = false;
            // 
            // Recently_deleted_first_picturebox
            // 
            this->Recently_deleted_first_picturebox->Location = System::Drawing::Point(1092, 156);
            this->Recently_deleted_first_picturebox->Name = L"Recently_deleted_first_picturebox";
            this->Recently_deleted_first_picturebox->Size = System::Drawing::Size(75, 68);
            this->Recently_deleted_first_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->Recently_deleted_first_picturebox->TabIndex = 33;
            this->Recently_deleted_first_picturebox->TabStop = false;
            // 
            // Recently_added_third_picturebox
            // 
            this->Recently_added_third_picturebox->Location = System::Drawing::Point(168, 402);
            this->Recently_added_third_picturebox->Name = L"Recently_added_third_picturebox";
            this->Recently_added_third_picturebox->Size = System::Drawing::Size(75, 68);
            this->Recently_added_third_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->Recently_added_third_picturebox->TabIndex = 32;
            this->Recently_added_third_picturebox->TabStop = false;
            // 
            // Recently_added_second_picturebox
            // 
            this->Recently_added_second_picturebox->Location = System::Drawing::Point(168, 285);
            this->Recently_added_second_picturebox->Name = L"Recently_added_second_picturebox";
            this->Recently_added_second_picturebox->Size = System::Drawing::Size(75, 68);
            this->Recently_added_second_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->Recently_added_second_picturebox->TabIndex = 31;
            this->Recently_added_second_picturebox->TabStop = false;
            // 
            // Recently_added_first_picturebox
            // 
            this->Recently_added_first_picturebox->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Recently_added_first_picturebox.Image")));
            this->Recently_added_first_picturebox->Location = System::Drawing::Point(168, 156);
            this->Recently_added_first_picturebox->Name = L"Recently_added_first_picturebox";
            this->Recently_added_first_picturebox->Size = System::Drawing::Size(75, 68);
            this->Recently_added_first_picturebox->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->Recently_added_first_picturebox->TabIndex = 30;
            this->Recently_added_first_picturebox->TabStop = false;
            // 
            // Recently_deleted_third_label
            // 
            this->Recently_deleted_third_label->AutoSize = true;
            this->Recently_deleted_third_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Recently_deleted_third_label->ForeColor = System::Drawing::Color::White;
            this->Recently_deleted_third_label->Location = System::Drawing::Point(1269, 415);
            this->Recently_deleted_third_label->Name = L"Recently_deleted_third_label";
            this->Recently_deleted_third_label->Size = System::Drawing::Size(53, 19);
            this->Recently_deleted_third_label->TabIndex = 29;
            this->Recently_deleted_third_label->Text = L"label13";
            // 
            // Recently_deleted_second_label
            // 
            this->Recently_deleted_second_label->AutoSize = true;
            this->Recently_deleted_second_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Recently_deleted_second_label->ForeColor = System::Drawing::Color::White;
            this->Recently_deleted_second_label->Location = System::Drawing::Point(1269, 307);
            this->Recently_deleted_second_label->Name = L"Recently_deleted_second_label";
            this->Recently_deleted_second_label->Size = System::Drawing::Size(53, 19);
            this->Recently_deleted_second_label->TabIndex = 28;
            this->Recently_deleted_second_label->Text = L"label13";
            // 
            // Recently_deleted_first_label
            // 
            this->Recently_deleted_first_label->AutoSize = true;
            this->Recently_deleted_first_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Recently_deleted_first_label->ForeColor = System::Drawing::Color::White;
            this->Recently_deleted_first_label->Location = System::Drawing::Point(1269, 180);
            this->Recently_deleted_first_label->Name = L"Recently_deleted_first_label";
            this->Recently_deleted_first_label->Size = System::Drawing::Size(53, 19);
            this->Recently_deleted_first_label->TabIndex = 27;
            this->Recently_deleted_first_label->Text = L"label13";
            // 
            // Recently_added_third_label
            // 
            this->Recently_added_third_label->AutoSize = true;
            this->Recently_added_third_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Recently_added_third_label->ForeColor = System::Drawing::Color::White;
            this->Recently_added_third_label->Location = System::Drawing::Point(14, 418);
            this->Recently_added_third_label->Name = L"Recently_added_third_label";
            this->Recently_added_third_label->Size = System::Drawing::Size(53, 19);
            this->Recently_added_third_label->TabIndex = 26;
            this->Recently_added_third_label->Text = L"label13";
            // 
            // Recently_added_second_label
            // 
            this->Recently_added_second_label->AutoSize = true;
            this->Recently_added_second_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Recently_added_second_label->ForeColor = System::Drawing::Color::White;
            this->Recently_added_second_label->Location = System::Drawing::Point(14, 307);
            this->Recently_added_second_label->Name = L"Recently_added_second_label";
            this->Recently_added_second_label->Size = System::Drawing::Size(53, 19);
            this->Recently_added_second_label->TabIndex = 25;
            this->Recently_added_second_label->Text = L"label13";
            // 
            // Recently_added_first_label
            // 
            this->Recently_added_first_label->AutoSize = true;
            this->Recently_added_first_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 8));
            this->Recently_added_first_label->ForeColor = System::Drawing::Color::White;
            this->Recently_added_first_label->Location = System::Drawing::Point(14, 180);
            this->Recently_added_first_label->Name = L"Recently_added_first_label";
            this->Recently_added_first_label->Size = System::Drawing::Size(53, 19);
            this->Recently_added_first_label->TabIndex = 24;
            this->Recently_added_first_label->Text = L"label13";
            // 
            // Recently_deleted_label
            // 
            this->Recently_deleted_label->AutoSize = true;
            this->Recently_deleted_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11));
            this->Recently_deleted_label->ForeColor = System::Drawing::Color::White;
            this->Recently_deleted_label->Location = System::Drawing::Point(1109, 97);
            this->Recently_deleted_label->Name = L"Recently_deleted_label";
            this->Recently_deleted_label->Size = System::Drawing::Size(235, 25);
            this->Recently_deleted_label->TabIndex = 23;
            this->Recently_deleted_label->Text = L"Recently Deleted Diseases";
            // 
            // Recently_added_label
            // 
            this->Recently_added_label->AutoSize = true;
            this->Recently_added_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 11));
            this->Recently_added_label->ForeColor = System::Drawing::Color::White;
            this->Recently_added_label->Location = System::Drawing::Point(14, 94);
            this->Recently_added_label->Name = L"Recently_added_label";
            this->Recently_added_label->Size = System::Drawing::Size(224, 25);
            this->Recently_added_label->TabIndex = 22;
            this->Recently_added_label->Text = L"Recently Added Diseases";
            // 
            // feed_background
            // 
            this->feed_background->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"feed_background.Image")));
            this->feed_background->Location = System::Drawing::Point(0, 0);
            this->feed_background->Margin = System::Windows::Forms::Padding(2);
            this->feed_background->Name = L"feed_background";
            this->feed_background->Size = System::Drawing::Size(1352, 715);
            this->feed_background->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->feed_background->TabIndex = 21;
            this->feed_background->TabStop = false;
            this->feed_background->Click += gcnew System::EventHandler(this, &MyForm::feed_background_Click);
            // 
            // feed_background_dark
            // 
            this->feed_background_dark->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"feed_background_dark.Image")));
            this->feed_background_dark->Location = System::Drawing::Point(0, -1);
            this->feed_background_dark->Margin = System::Windows::Forms::Padding(2);
            this->feed_background_dark->Name = L"feed_background_dark";
            this->feed_background_dark->Size = System::Drawing::Size(1352, 715);
            this->feed_background_dark->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
            this->feed_background_dark->TabIndex = 54;
            this->feed_background_dark->TabStop = false;
            // 
            // timer4
            // 
            this->timer4->Interval = 150;
            this->timer4->Tick += gcnew System::EventHandler(this, &MyForm::timer4_Tick);
            // 
            // timer5
            // 
            this->timer5->Interval = 150;
            this->timer5->Tick += gcnew System::EventHandler(this, &MyForm::timer5_Tick);
            // 
            // timer6
            // 
            this->timer6->Interval = 1;
            this->timer6->Tick += gcnew System::EventHandler(this, &MyForm::timer6_Tick);
            // 
            // timer7
            // 
            this->timer7->Interval = 1;
            this->timer7->Tick += gcnew System::EventHandler(this, &MyForm::timer7_Tick);
            // 
            // timer8
            // 
            this->timer8->Interval = 70;
            this->timer8->Tick += gcnew System::EventHandler(this, &MyForm::timer8_Tick);
            // 
            // timer9
            // 
            this->timer9->Interval = 70;
            this->timer9->Tick += gcnew System::EventHandler(this, &MyForm::timer9_Tick);
            // 
            // timer10
            // 
            this->timer10->Interval = 70;
            this->timer10->Tick += gcnew System::EventHandler(this, &MyForm::timer10_Tick);
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackColor = System::Drawing::SystemColors::ActiveCaption;
            this->ClientSize = System::Drawing::Size(1699, 831);
            this->ControlBox = false;
            this->Controls->Add(this->label11);
            this->Controls->Add(this->Register);
            this->Controls->Add(this->Sign_in);
            this->Controls->Add(this->panel3);
            this->Controls->Add(this->panel5);
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
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox37))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox38))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox39))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox40))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox41))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox42))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox43))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox12))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox10))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox11))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox13))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox14))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox15))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox18))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox31))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
            this->panel5->ResumeLayout(false);
            this->panel5->PerformLayout();
            this->panel6->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox36))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox35))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox34))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox21))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox20))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox33))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox32))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox30))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox25))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox23))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox22))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox19))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox24))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox26))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox29))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox28))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox27))->EndInit();
            this->feed_panel->ResumeLayout(false);
            this->feed_panel->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->back_feed_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->second_most_front_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->third_most_front_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->most_front_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->third_most_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->second_most_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Most_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->x_axis_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->y_axis_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_deleted_third_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_deleted_second_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_deleted_first_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_added_third_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_added_second_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Recently_added_first_picturebox))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed_background))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->feed_background_dark))->EndInit();
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
            button9->Hide();
            Sign_in->Text = "Sign-in.";
            textBox1->Focus();
        }
        else {
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
        DoubleBuffered = true;
        Opacity = 0;
        timer4->Start();
        getAllDoctors(allDoctors);
        getAllPatients(allPatients);
        getAllDiseases((&allDiseases));
        extract_Symptoms();
        extract_disease_to_doctor();
        ValidatoryData();
        backgrounds->Add(pictureBox1);
        backgrounds->Add(pictureBox18);
        backgrounds->Add(pictureBox27);
        backgrounds->Add(feed_background);
        light_pic = pictureBox1->Image;
        Bitmap ^img = gcnew Bitmap(back_feed_picturebox->Image);
        img->RotateFlip(RotateFlipType::Rotate90FlipNone);
        back_feed_picturebox->Image = img;
        back_feed_picturebox->Parent = feed_background;
        back_feed_picturebox->BackColor = BackColor.Transparent;



        GraphicsPath^ gp = gcnew GraphicsPath();
        gp->AddEllipse(pictureBox32->DisplayRectangle);
        pictureBox32->Region = gcnew System::Drawing::Region(gp);


        GraphicsPath^ gp1 = gcnew GraphicsPath();
        gp1->AddEllipse(pictureBox36->DisplayRectangle);
        pictureBox36->Region = gcnew System::Drawing::Region(gp1);

        GraphicsPath^ gp2 = gcnew GraphicsPath();
        gp2->AddEllipse(pictureBox43->DisplayRectangle);
        pictureBox43->Region = gcnew System::Drawing::Region(gp2);

        GraphicsPath^ gp3 = gcnew GraphicsPath();
        gp3->AddEllipse(pictureBox37->DisplayRectangle);
        pictureBox37->Region = gcnew System::Drawing::Region(gp3);


        button9->Hide();
        pictureBox1->SendToBack();
        Username->Parent = pictureBox1;
        Username->BackColor = BackColor.Transparent;
        Password->Parent = pictureBox1;
        Password->BackColor = BackColor.Transparent;
        pictureBox6->Parent = pictureBox1;
        pictureBox6->BackColor = BackColor.Transparent;
        pictureBox7->Parent = pictureBox1;
        pictureBox7->BackColor = BackColor.Transparent;
        email_togglebutton->Parent = pictureBox1;
        email_togglebutton->BackColor = BackColor.Transparent;
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
        label19->Parent = pictureBox18;
        label19->BackColor = BackColor.Transparent;
        label17->Parent = pictureBox18;
        label17->BackColor = BackColor.Transparent;
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


        pictureBox33->Parent = pictureBox27;
        pictureBox33->BackColor = BackColor.Transparent;

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
        pictureBox42->BackColor = BackColor.Transparent;
        pictureBox42->Parent = pictureBox18;
        pictureBox15->BackColor = BackColor.Transparent;
        pictureBox19->Parent = pictureBox27;
        pictureBox19->BackColor = BackColor.Transparent;
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
        Most_value->Hide();
        second_most_value->Hide();
        third_most_value->Hide();
        Most_name_label->Hide();
        Second_Most_name_label->Hide();
        Third_Most_name_label->Hide();
        //remove_disease_gbox->Parent = pictureBox27;
        //remove_disease_gbox->BackColor = Color::FromArgb(100, 0, 0, 0);
        //Remove_symps_Gbox->Parent = pictureBox27;
        //Remove_symps_Gbox->BackColor = Color::FromArgb(100, 0, 0, 0);

        most_front_picturebox->Parent = feed_background;
        most_front_picturebox->BackColor = BackColor.Transparent; 
        Recently_added_label->Parent = feed_background;
        Recently_added_label->BackColor = BackColor.Transparent; 
        Recently_added_first_label->Parent = feed_background;
        Recently_added_first_label->BackColor = BackColor.Transparent;
        Recently_added_second_label->Parent = feed_background;
        Recently_added_second_label->BackColor = BackColor.Transparent;
        Recently_added_third_label->Parent = feed_background;
        Recently_added_third_label->BackColor = BackColor.Transparent;
        Recently_deleted_label->Parent = feed_background;
        Recently_deleted_label->BackColor = BackColor.Transparent;
        Recently_deleted_first_label->Parent = feed_background;
        Recently_deleted_first_label->BackColor = BackColor.Transparent;
        Recently_deleted_second_label->Parent = feed_background;
        Recently_deleted_second_label->BackColor = BackColor.Transparent;
        Recently_deleted_third_label->Parent = feed_background;
        Recently_deleted_third_label->BackColor = BackColor.Transparent;
        Title_feed->Parent = feed_background;
        Title_feed->BackColor = BackColor.Transparent;
        Most_name_label->Parent = feed_background;
        Most_name_label->BackColor = BackColor.Transparent;
        Second_Most_name_label->Parent = feed_background;
        Second_Most_name_label->BackColor = BackColor.Transparent;
        Third_Most_name_label->Parent = feed_background;
        Third_Most_name_label->BackColor = BackColor.Transparent;
        Most_value->Parent = feed_background;
        Most_value->BackColor = BackColor.Transparent;
        second_most_value->Parent = feed_background;
        second_most_value->BackColor = BackColor.Transparent;
        third_most_value->Parent = feed_background;
        third_most_value->BackColor = BackColor.Transparent;

        second_most_front_picturebox->Parent = feed_background;
        second_most_front_picturebox->BackColor = BackColor.Transparent;
        third_most_front_picturebox->Parent = feed_background;
        third_most_front_picturebox->BackColor = BackColor.Transparent;
        Most_picturebox->Parent = feed_background;
        second_most_picturebox->Parent = feed_background;
        third_most_picturebox->Parent = feed_background;

        label13->Parent = pictureBox1;
        label13->BackColor = BackColor.Transparent;


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
        label20->Hide();
        label21->Hide();
        pictureBox20->Hide();
        pictureBox21->Hide();
        pictureBox33->Hide();
        pictureBox34->Hide();
        pictureBox35->Hide();
        label35->Hide();
        pictureBox36->Hide();
        label36->Hide();
        label37->Hide();
        label38->Hide();
        pictureBox38->Hide();
        pictureBox40->Hide();
        pictureBox41->Hide();
        pictureBox42->Hide();
        pictureBox39->Hide();
        pictureBox37->Hide();
        feed_panel->Hide();
        label13->Hide();
        email_togglebutton->Hide();
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
                    this->ActiveControl = Username;
                    panel4->Show();
                    panel5->Show();
                    current_doctor_diseases_listbox->Hide();
                    removed_diseases_listbox->Hide();
                    add_disease_to_removed_button->Hide();
                    remove_disease_from_removed_button->Hide();
                    delete_diseases_button->Hide();
                    clear_removed_diseases_button->Hide();
                    remove_all_diseases_button->Hide();
                    Current_doc_diseases_combobox->Hide();
                    removed_symps_listbox->Hide();
                    current_disease_symps_listbox->Hide();
                    add_symp_to_removed_button->Hide();
                    remove_symp_from_removed_button->Hide();
                    delete_symps_button->Hide();
                    clear_remove_list_button->Hide();
                    Remove_all_symps_button->Hide();
                    Patients_of_chosen_disease_listbox->Hide();
                    Alldiseases_combobox->Hide();
                    Disease_docname_textbox->Hide();
                    Disease_doc_phone_textbox->Hide();
                    Disease_info_textbox->Hide();
                    Disease_symps_listbox->Hide();
                    Disease_name_textbox->Hide();
                    label2->Hide();
                    PrintDoctorMenu();
                    Form::Width -= 200;
                    Form::Height -= 150;
                    textBox2->Select(0, 0);

                    label6->ForeColor = Color::FromArgb(255, 255, 255);
                    label5->ForeColor = Color::FromArgb(255, 255, 255);
                }
                else if (patientLogin(allPatients, username, password, CurrentPatient, index_allPatients)) {
                    this->ActiveControl = Username;
                    panel4->Show();
                    panel5->Hide();
                    label2->Hide();
                    printPatientMenu();
                    Form::Width -= 200;
                    Form::Height -= 150;
                    textBox2->Select(0, 0);

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
        bool test_email = false;
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
                                            MyForm2^ sc = gcnew MyForm2(randomCode, allPatients[i].account.username, allPatients[i].account.password);
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
                                pat_phone = "";
                                for (int i = 0; i < lengthCount; i++) {
                                    pat_phone += to_string(check[i]);
                                }
                                if (check_phone(pat_phone)) {
                                    Username->Text = "Please select Age";
                                    textBox2->Hide();
                                    panel2->Hide();
                                    textBox1->Hide();
                                    textBox3->Show();
                                    Password->Hide();
                                }
                                else {
                                    label2->Text = "phone number is already taken";
                                    label2->Show();
                                    textBox3->Text = "";
                                }

                            }
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

                    if (textBox1->Text != "") {
                        string new_email;
                        MarshalString(textBox1->Text, new_email);
                        string domains[6] = { "gmail.com","outlook.com","yahoo.com","hotmail.com","icloud.com","cis.asu.edu.eg" };
                        int at_index = new_email.find("@");
                        string email_username = new_email.substr(0, at_index);
                        for (int i = 0; i < at_index; i++)
                        {
                            if (email_username[i] != '.' && !isalnum(email_username[i]))
                            {
                                test_email = false;
                                label2->Text = "Invalid email\n";
                                label2->Show();
                                test_email = false;
                                break;
                            }
                            else {
                                test_email = true;
                            }
                        }
                        if(test_email){
                        for (int i = 0; i < 6; i++) {
                            if (new_email.find(domains[i], at_index) == -1) {
                                label2->Text = "Invalid email\n";
                                label2->Show();
                                test_email = false;
                               
                            }
                            else {
                                test_email = true;
                                break;
                            }
                        }
                        }


                        if (test_email) {
                            if (check_database_email(new_email)) {

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
                                    label13->Show();
                                    email_togglebutton->Show();
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
                        if (textBox1->Text != "") {
                            string new_email;
                            MarshalString(textBox1->Text, new_email);
                            string domains[6] = { "gmail.com","outlook.com","yahoo.com","hotmail.com","icloud.com","cis.asu.edu.eg" };
                            int at_index = new_email.find("@");
                            string email_username = new_email.substr(0, at_index);
                            for (int i = 0; i < at_index; i++)
                            {
                                if (email_username[i] != '.' && !isalnum(email_username[i]))
                                {
                                    test_email = false;
                                    label2->Text = "Invalid email\n";
                                    label2->Show();
                                    test_email = false;
                                    break;
                                }
                                else {
                                    test_email = true;
                                }
                            }
                            if (test_email) {
                                for (int i = 0; i < 6; i++) {
                                    if (new_email.find(domains[i], at_index) == -1) {
                                        label2->Text = "Invalid email\n";
                                        label2->Show();
                                        test_email = false;
                                    }
                                    else {
                                        test_email = true;
                                        break;
                                    }
                                }
                            }


                            if (test_email) {
                                if (check_database_email(new_email)) {

                                    MyCamera->Start(0);
                                    pictureBox31->Show();
                                    button9->Show();
                                    label34->Show();
                                    button8->Show();
                                    Next->Text = "Capture";
                                    Username->Text = "Cam";
                                    label2->Hide();
                                    label13->Hide();
                                    email_togglebutton->Hide();
                                }
                                else {
                                    label2->Show();
                                    label2->Text = "This Email is used by an another account";
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
            button1->Text = "Sign-in";
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
            button9->Hide();
            textBox1->Focus();

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
            label3->Text = "DOCTOR";
            label4->Text = "PATIENT";
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
            button9->Hide();
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
        textBox1->Focus();
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
        textBox1->Focus();
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
        Patient New_Patient = { pat_name, {pat_username, pat_password,mail}, Pat_gender[0], stoi(pat_age),pat_phone };
        allPatients[index_allPatients] = New_Patient;
        CurrentPatient = &allPatients[index_allPatients];
        index_allPatients++;
        this->ActiveControl = Username;
        panel4->Show();
        panel5->Hide();
        Form::Width -= 200;
        Form::Height -= 150;
        printPatientMenu();
        textBox2->Select(0, 0);


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
        Patient New_Patient = { pat_name, {pat_username, pat_password,mail}, Pat_gender[0], stoi(pat_age),pat_phone };
        allPatients[index_allPatients] = New_Patient;
        CurrentPatient = &allPatients[index_allPatients];
        index_allPatients++;
        this->ActiveControl = Username;
        panel4->Show();
        panel5->Hide();
        Form::Width -= 200;
        Form::Height -= 150;
        printPatientMenu();
        textBox2->Select(0, 0);

    }


    private: System::Void label7_Click(System::Object^ sender, System::EventArgs^ e) {
    }

    private: System::Void panel3_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
    }
    private: System::Void pictureBox16_Click(System::Object^ sender, System::EventArgs^ e) {

    }
    private: System::Void pictureBox17_Click(System::Object^ sender, System::EventArgs^ e) {

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

        if (textBox4->Text != "" && check1 == true) {
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
                String^ str2 = gcnew String(Disease_Diagnosed[index_self - 1].name.c_str());
                string per = to_string(percentage_of_diagnosed_Disease[index_self - 1] * 100);
                per = per.substr(0, 4);
                String^ percentage = gcnew String(per.c_str());
                String^ info = gcnew String(Disease_Diagnosed[index_self - 1].info.c_str());
                label19->Text = String::Format("You are {0}% diagnosed with: {1}\nGeneral Information:\n{2}\nYou may feel symptoms like:", percentage, str2, info);
                for (int j = 1; j <= Disease_Diagnosed[index_self - 1].symps.size(); j++) {
                    string symp = Disease_Diagnosed[index_self - 1].symps[j - 1];
                    String^ symptom = gcnew String(symp.c_str());
                    String^ index1 = gcnew String(to_string(j).c_str());
                    if (j == 1 || j % 5 == 0)
                        label19->Text += String::Format("\n{0}-{1}", index1, symptom);
                    else
                        label19->Text += String::Format("     {0}-{1}", index1, symptom);
                }
                String^ name = gcnew String(Disease_Diagnosed[index_self - 1].doc_name.c_str());
                String^ phone = gcnew String(Disease_Diagnosed[index_self - 1].doc_phone.c_str());
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
                MessageBody = (*CurrentPatient).patient_name + " has been diagnosed with " + Disease_Diagnosed[index_self - 1].name + ".\nfor contact: " + (*CurrentPatient).account.email;
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

                label17->Text = "You are not diagnosed with any Diseases,\nHere is the closest disease related to your symptoms:\n";
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
                    String^ str2 = gcnew String(Related_Diseases[index_related - 1].name.c_str());
                    string per = to_string(percentage_of_related_Disease[index_related - 1] * 100);
                    per = per.substr(0, 4);
                    String^ percentage = gcnew String(per.c_str());
                    String^ info = gcnew String(Related_Diseases[index_related - 1].info.c_str());
                    label19->Text += String::Format("{0}-{1} with {2}%\nGeneral Information:\n{3}\nYou may feel symptoms like", index, str2, percentage, info);
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
        label29->Text = "CCCCCCCCCCCCCCCCC";
        button6->PerformClick();
        panel4->TabIndex -= 5;
        System::Windows::Forms::SendKeys::Send("%");
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
        /*if (MessageBox::Show("Are you sure you want to quit?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
            writeAllPatients(allPatients);
            writeAllDiseases(allDiseases);
            writeAllDoctors(allDoctors);
        }*/
        this->Close();
        System::Windows::Forms::SendKeys::Send("%");
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
                            String^ str3 = gcnew String(Patient_with_Disease[i - 1].c_str());
                            if (i == 1 || i % 5 == 0)
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
                        if (MessageBox::Show(String::Format("Are you sure you want to delete {0}", str2), str2, MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
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
            else if (label29->Text == "Please choose Which disease you want\nto delete its symptoms....") {
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
                            label29->Text = "wEEE";
                            textBox5->Hide();
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

        else if (label29->Text[0] == 'C' || label29->Text[0] == 'W' || label31->Text == "Please enter the disease name:" || label29->Text == "Please choose Which disease you want\nto add its symptoms...." || label29->Text == "Please choose Which disease you want\nto delete its symptoms..") { //Choose disease to view
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
        else if (label31->Text == "Please enter number of symptoms:") {
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
                allsymps.erase(allsymps.begin() + (index_symp - 1));
            }
            index_symp--;
            String^ index = gcnew String(to_string(index_symp).c_str());
            label31->Text = String::Format("Symptom #{0}", index);
            textBox5->Text = "";
            button4->Text = "Next";
        }
        else if (label31->Text == "there is no Symptoms for this disease" || label29->Text == "Please choose Which symptom you want to remove ....") {
            label29->Text = "Please choose Which disease you want\nto delete its symptoms..";
            label31->Text = "weeeeeeeeee";
            label31->Hide();
            button4->Text = "Next";
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
        textBox6->Focus();
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
        feed_panel->Show();
        timer6->Start();
        Feed();

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
        label2->Text = "";
        label2->Hide();
        button5->Location = Drawing::Point(1180, 479);

    }
    private: System::Void label33_MouseHover(System::Object^ sender, System::EventArgs^ e) {
        label33->ForeColor = Color::FromArgb(255, 255, 255);
    }
    private: System::Void label33_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
        label33->ForeColor = Color::FromArgb(0, 0, 0);
    }
    private: System::Void button5_Click_2(System::Object^ sender, System::EventArgs^ e) {
        if (Password->Text == "E-Mail" && Username->Text == "Username") {
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
            Username->Text = "Mobile Phone Number";
            textBox2->Hide();
            panel2->Hide();
            textBox1->Hide();
            textBox3->Show();
            textBox3->Text = "";
            Password->Hide();
        }
        else if (Username->Text == "E-Mail" && label11->Text == "p") {
            textBox3->Show();
            textBox1->Text = "";
            textBox1->Hide();
            Username->Text = "Please select Age";
            label2->Hide();
        }
        else if (Username->Text == "E-Mail" && label11->Text == "d") {
            textBox1->Hide();
            textBox1->Text = "";
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
            textBox3->Text = "";
            textBox1->Text = "";
            textBox2->Text = "";
        }
        else if (Next->Text == "Capture" || Next->Text == "Retake" || Next->Text == "Take a Picture") {
        if (label11->Text == "d") {
            label13->Show();
            email_togglebutton->Show();
        }
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
            button8->Text = "No Profile Picture";

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

        if (button8->Text == "End" || (button8->Text == "No Profile Picture" && label11->Text == "d")) {

            MyCamera->Stop();
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
            Doctors NewDoctor = { doc_name,{doc_username, doc_password, mail }, doctor_phone, send_email};
            allDoctors[index_allDoctors] = NewDoctor;
            CurrentDoctor = &allDoctors[index_allDoctors];
            index_allDoctors++;
            this->ActiveControl = Username;
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
        else if (button8->Text == "Next" || label11->Text == "p") {
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
        dialog->Filter = str3;
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
        if (e->KeyCode == Keys::Enter && !panel4->Visible)
        {
            if (button1->Visible || Username->Text == "Password") {
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
        if (e->KeyCode == Keys::Enter && !panel4->Visible)
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
        if (!open) {
            open = true;
            pictureBox33->Show();
            label20->Show();
            label21->Show();
            label35->Show();
            pictureBox21->Show();
            pictureBox20->Show();
            pictureBox34->Show();
            pictureBox35->Show();
            pictureBox36->Show();

        }
        else {
            open = false;
            pictureBox33->Hide();
            label20->Hide();
            label21->Hide();
            label35->Hide();
            pictureBox21->Hide();
            pictureBox20->Hide();
            pictureBox34->Hide();
            pictureBox35->Hide();
            pictureBox36->Hide();
        }
    }
    private: System::Void pictureBox33_Click(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void Account_settings_Click(System::Object^ sender, System::EventArgs^ e) {



    }
    private: System::Void MyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
        if (Opacity > 0) {
            System::Windows::Forms::SendKeys::Send("%");
            if (MessageBox::Show("Are you sure you want to quit?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::No) {
                e->Cancel = true;
            }
            else {
                e->Cancel = true;
                writeAllPatients(allPatients);
                writeAllDiseases(allDiseases);
                writeAllDoctors(allDoctors);
                panel4->Hide();
                panel5->Hide();
                timer5->Start();
                if (MyForm::Opacity == 0) {
                    e->Cancel = false;
                    this->Close();
                }

            }
        }
    }


    private: System::Void pictureBox35_Click(System::Object^ sender, System::EventArgs^ e) {
        Account_Settings^ sc = gcnew Account_Settings((*CurrentDoctor).doc_name, (*CurrentDoctor).account.username, (*CurrentDoctor).account.password, (*CurrentDoctor).account.email, (*CurrentDoctor).phone, (*CurrentDoctor).send_email, allEmails, allPhones, allUsernames);
        this->Hide();
        sc->ShowDialog();
        this->Show();
        if (sc->save_key()) {
            string wow = "PICs\\Doctors\\" + (*CurrentDoctor).account.username + ".jpg";
            String^ str3 = gcnew String(wow.c_str());
            if (System::IO::File::Exists(str3)) {
                pictureBox32->ImageLocation = str3;
                pictureBox36->ImageLocation = str3;
            }
            else {
                pictureBox32->ImageLocation = "PICs\\guest.jpg";
                pictureBox36->ImageLocation = "PICs\\guest.jpg";
            }
            label30->Text = "Hello Dr. " + sc->GetFullname();
            MarshalString(sc->GetUsername(), (*CurrentDoctor).account.username);
            MarshalString(sc->GetPass(), (*CurrentDoctor).account.password);
            MarshalString(sc->GetFullname(), (*CurrentDoctor).doc_name);
            MarshalString(sc->GetEmail(), (*CurrentDoctor).account.email);
            MarshalString(sc->GetPhone(), (*CurrentDoctor).phone);
            (*CurrentDoctor).send_email = sc->Getsend_email();
        }

        if (sc->logout()) {
            logout_back();
        }
        open = false;
        pictureBox33->Hide();
        label20->Hide();
        label21->Hide();
        label35->Hide();
        pictureBox21->Hide();
        pictureBox20->Hide();
        pictureBox34->Hide();
        pictureBox35->Hide();
        pictureBox36->Hide();
    }
    private: System::Void pictureBox41_Click(System::Object^ sender, System::EventArgs^ e) {
        if (MessageBox::Show("Are you sure you want to Logout?", "Logout?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
            logout_back();
        }
    }
    private: System::Void pictureBox40_Click(System::Object^ sender, System::EventArgs^ e) {
        System::Windows::Forms::SendKeys::Send("%");
        /* if (MessageBox::Show("Are you sure you want to quit?", "Quit?", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
             writeAllPatients(allPatients);
             writeAllDiseases(allDiseases);
             writeAllDoctors(allDoctors);
         }*/
        this->Close();
    }
    private: System::Void pictureBox43_Click(System::Object^ sender, System::EventArgs^ e) {
        if (!open1) {
            open1 = true;
            pictureBox37->Show();
            label36->Show();
            label37->Show();
            label38->Show();
            pictureBox38->Show();
            pictureBox40->Show();
            pictureBox41->Show();
            pictureBox42->Show();
            pictureBox39->Show();
            pictureBox37->Show();

        }
        else {
            open1 = false;
            label36->Hide();
            label37->Hide();
            label38->Hide();
            pictureBox38->Hide();
            pictureBox40->Hide();
            pictureBox41->Hide();
            pictureBox42->Hide();
            pictureBox39->Hide();
            pictureBox37->Hide();

        }
    }
    private: System::Void pictureBox38_Click(System::Object^ sender, System::EventArgs^ e) {
        Account_Settings^ sc = gcnew Account_Settings((*CurrentPatient).patient_name, (*CurrentPatient).account.username, (*CurrentPatient).account.password, (*CurrentPatient).account.email, (*CurrentPatient).gender, allEmails, allPhones, allUsernames);
        this->Hide();
        sc->ShowDialog();
        this->Show();
        if (sc->save_key()) {
            string wow = "PICs\\Doctors\\" + (*CurrentDoctor).account.username + ".jpg";
            String^ str3 = gcnew String(wow.c_str());
            if (System::IO::File::Exists(str3)) {
                pictureBox32->ImageLocation = str3;
                pictureBox36->ImageLocation = str3;
            }
            else {
                pictureBox32->ImageLocation = "PICs\\guest.jpg";
                pictureBox36->ImageLocation = "PICs\\guest.jpg";
            }
            label30->Text = "Hello Dr. " + sc->GetFullname();
            MarshalString(sc->GetUsername(), (*CurrentDoctor).account.username);
            MarshalString(sc->GetPass(), (*CurrentDoctor).account.password);
            MarshalString(sc->GetFullname(), (*CurrentDoctor).doc_name);
            MarshalString(sc->GetEmail(), (*CurrentDoctor).account.email);
            MarshalString(sc->GetPhone(), (*CurrentDoctor).phone);
            (*CurrentDoctor).send_email = sc->Getsend_email();
        }
        if (sc->logout()) {
            logout_back();
        }
        open1 = false;
        label36->Hide();
        label37->Hide();
        label38->Hide();
        pictureBox38->Hide();
        pictureBox40->Hide();
        pictureBox41->Hide();
        pictureBox42->Hide();
        pictureBox39->Hide();
        pictureBox37->Hide();
    }
    private: System::Void timer4_Tick(System::Object^ sender, System::EventArgs^ e) {
        if (Opacity == 1) {
            timer4->Stop();
       
        }
        Opacity += .2;
    }
    private: System::Void timer5_Tick(System::Object^ sender, System::EventArgs^ e) {
        if (Opacity <= 0) {
            timer5->Stop();
            this->Close();
        }
        MyForm::Opacity -= .2;
    }
    private: System::Void Current_doc_diseases_combobox_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
        current_disease_symps_listbox->Items->Clear();
        string selected_disease;
        MarshalString(Current_doc_diseases_combobox->Text, selected_disease);
        for (int disease = 0; disease < (*CurrentDoctor).doc_diseases.size(); disease++) {
            if ((*CurrentDoctor).doc_diseases[disease].name == selected_disease) {
                for (int symp = 0; symp < (*CurrentDoctor).doc_diseases[disease].symps.size(); symp++) {
                    String^ newsymp = gcnew String((*CurrentDoctor).doc_diseases[disease].symps[symp].c_str());
                    current_disease_symps_listbox->Items->Add(newsymp);
                }
            }
        }
    }
    private: System::Void add_symp_to_removed_button_Click(System::Object^ sender, System::EventArgs^ e) {
        for each (auto selecteditem in current_disease_symps_listbox->SelectedItems) {
            removed_symps_listbox->Items->Add(selecteditem);

        }
        for (int i = current_disease_symps_listbox->SelectedItems->Count - 1; i >= 0; i--) {
            current_disease_symps_listbox->Items->Remove(current_disease_symps_listbox->SelectedItems[i]);

        }
    }
    private: System::Void remove_symp_from_removed_button_Click(System::Object^ sender, System::EventArgs^ e) {
        for each (auto selecteditem in removed_symps_listbox->SelectedItems) {
            current_disease_symps_listbox->Items->Add(selecteditem);

        }
        for (int i = removed_symps_listbox->SelectedItems->Count - 1; i >= 0; i--) {
            removed_symps_listbox->Items->Remove(removed_symps_listbox->SelectedItems[i]);

        }
    }
    private: System::Void Remove_all_symps_button_Click(System::Object^ sender, System::EventArgs^ e) {
        while (current_disease_symps_listbox->Items->Count != 0) {
            for (int i = 0; i < current_disease_symps_listbox->Items->Count; i++) {
                removed_symps_listbox->Items->Add(current_disease_symps_listbox->Items[i]);
                current_disease_symps_listbox->Items->Remove(current_disease_symps_listbox->Items[i]);
                if (current_disease_symps_listbox->Items->Count == 0) {
                    break;
                }
            }
        }
    }
    private: System::Void clear_remove_list_button_Click(System::Object^ sender, System::EventArgs^ e) {
        while (removed_symps_listbox->Items->Count != 0) {
            for (int i = 0; i < removed_symps_listbox->Items->Count; i++) {
                current_disease_symps_listbox->Items->Add(removed_symps_listbox->Items[i]);
                removed_symps_listbox->Items->Remove(removed_symps_listbox->Items[i]);
                if (removed_symps_listbox->Items->Count == 0) {
                    break;
                }

            }
        }
    }
    private: System::Void delete_symps_button_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ sympo;
        string symp;
        string selected_disease;
        MarshalString(Current_doc_diseases_combobox->Text, selected_disease);

        if (removed_symps_listbox->Items->Count > 1) {
            if (MessageBox::Show("Are you sure you want to delete those symptoms ?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                for (int disease = 0; disease < (*CurrentDoctor).doc_diseases.size(); disease++) {
                    if ((*CurrentDoctor).doc_diseases[disease].name == selected_disease) {
                        for each (auto removedsymp in removed_symps_listbox->Items)
                        {
                            sympo = removedsymp->ToString();
                            MarshalString(sympo, symp);
                            for (int symp_index = 0; symp_index < (*CurrentDoctor).doc_diseases[disease].symps.size(); symp_index++) {
                                if ((*CurrentDoctor).doc_diseases[disease].symps[symp_index] == symp) {
                                    remove_symptom_from_all_Symptoms((*CurrentDoctor).doc_diseases[disease], symp_index);
                                    remove_symptom_from_all_Disease((*CurrentDoctor).doc_diseases[disease], symp_index);
                                    (*CurrentDoctor).doc_diseases[disease].symps.erase((*CurrentDoctor).doc_diseases[disease].symps.begin() + symp_index);
                                }
                            }
                            //auto index_symp;

                           //(*CurrentDoctor).doc_diseases[disease].symps.erase((*CurrentDoctor).doc_diseases[disease].symps.begin()+);
                        }
                        removed_symps_listbox->Items->Clear();
                        break;
                    }
                }

            }
            

        }
        else if (removed_symps_listbox->Items->Count == 1) {
            if (MessageBox::Show("Are you sure you want to delete this symptom ?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                for (int disease = 0; disease < (*CurrentDoctor).doc_diseases.size(); disease++) {
                    if ((*CurrentDoctor).doc_diseases[disease].name == selected_disease) {
                        for each (auto removedsymp in removed_symps_listbox->Items)
                        {
                            sympo = removedsymp->ToString();
                            MarshalString(sympo, symp);
                            for (int symp_index = 0; symp_index < (*CurrentDoctor).doc_diseases[disease].symps.size(); symp_index++) {
                                if ((*CurrentDoctor).doc_diseases[disease].symps[symp_index] == symp) {
                                    remove_symptom_from_all_Symptoms((*CurrentDoctor).doc_diseases[disease], symp_index);
                                    remove_symptom_from_all_Disease((*CurrentDoctor).doc_diseases[disease], symp_index);
                                    (*CurrentDoctor).doc_diseases[disease].symps.erase((*CurrentDoctor).doc_diseases[disease].symps.begin() + symp_index);
                                }
                            }
                        }
                        removed_symps_listbox->Items->Clear();
                        allSymptoms.clear();
                        extract_Symptoms();
                        break;
                    }
                }
            }
        }
        else
            MessageBox::Show("You didn't select any symptom !!", "Alert", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    private: System::Void add_disease_to_removed_button_Click(System::Object^ sender, System::EventArgs^ e) {
        for each (auto selecteditem in current_doctor_diseases_listbox->SelectedItems) {
            removed_diseases_listbox->Items->Add(selecteditem);

        }
        for (int i = current_doctor_diseases_listbox->SelectedItems->Count - 1; i >= 0; i--) {
            current_doctor_diseases_listbox->Items->Remove(current_doctor_diseases_listbox->SelectedItems[i]);

        }
    }
    private: System::Void remove_disease_from_removed_button_Click(System::Object^ sender, System::EventArgs^ e) {
        for each (auto selecteditem in removed_diseases_listbox->SelectedItems) {
            current_doctor_diseases_listbox->Items->Add(selecteditem);

        }
        for (int i = removed_diseases_listbox->SelectedItems->Count - 1; i >= 0; i--) {
            removed_diseases_listbox->Items->Remove(removed_diseases_listbox->SelectedItems[i]);

        }
    }
    private: System::Void remove_all_diseases_button_Click(System::Object^ sender, System::EventArgs^ e) {
        while (current_doctor_diseases_listbox->Items->Count != 0) {
            for (int i = 0; i < current_doctor_diseases_listbox->Items->Count; i++) {
                removed_diseases_listbox->Items->Add(current_doctor_diseases_listbox->Items[i]);
                current_doctor_diseases_listbox->Items->Remove(current_doctor_diseases_listbox->Items[i]);
                if (current_doctor_diseases_listbox->Items->Count == 0) {
                    break;
                }
            }
        }
    }
    private: System::Void clear_removed_diseases_button_Click(System::Object^ sender, System::EventArgs^ e) {
        while (removed_diseases_listbox->Items->Count != 0) {
            for (int i = 0; i < removed_diseases_listbox->Items->Count; i++) {
                current_doctor_diseases_listbox->Items->Add(removed_diseases_listbox->Items[i]);
                removed_diseases_listbox->Items->Remove(removed_diseases_listbox->Items[i]);
                if (removed_diseases_listbox->Items->Count == 0) {
                    break;
                }

            }
        }
    }
    private: System::Void delete_diseases_button_Click(System::Object^ sender, System::EventArgs^ e) {
        String^ diso;
        string selected_disease;
        if (removed_diseases_listbox->Items->Count > 1) {
            if (MessageBox::Show("Are you sure you want to delete those Diseases ?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                for (int disease_index = 0; disease_index < (*CurrentDoctor).doc_diseases.size(); disease_index++) {
                    for each (auto removeddis in removed_diseases_listbox->Items)
                    {
                        diso = removeddis->ToString();
                        MarshalString(diso, selected_disease);
                        if ((*CurrentDoctor).doc_diseases[disease_index].name == selected_disease) {
                            remove_symptom_from_all_Symptoms((*CurrentDoctor).doc_diseases[disease_index]);
                            remove_Disease_from_all_Diseases((*CurrentDoctor).doc_diseases[disease_index]);
                            (*CurrentDoctor).doc_diseases.erase((*CurrentDoctor).doc_diseases.begin() + disease_index);

                        }
                        /*removed_symps_listbox->Items->Clear();
                        break;*/
                    }
                }

            }

        }
        else if (removed_diseases_listbox->Items->Count == 1) {
            if (MessageBox::Show("Are you sure you want to delete this Disease ?", "Confirm", MessageBoxButtons::YesNo, MessageBoxIcon::Question) == System::Windows::Forms::DialogResult::Yes) {
                for (int disease_index = 0; disease_index < (*CurrentDoctor).doc_diseases.size(); disease_index++) {
                    for each (auto removeddis in removed_diseases_listbox->Items)
                    {
                        diso = removeddis->ToString();
                        MarshalString(diso, selected_disease);
                        if ((*CurrentDoctor).doc_diseases[disease_index].name == selected_disease) {
                            remove_symptom_from_all_Symptoms((*CurrentDoctor).doc_diseases[disease_index]);
                            remove_Disease_from_all_Diseases((*CurrentDoctor).doc_diseases[disease_index]);
                            (*CurrentDoctor).doc_diseases.erase((*CurrentDoctor).doc_diseases.begin() + disease_index);
                            
                        }
                        removed_diseases_listbox->Items->Clear();
                        allSymptoms.clear();
                        extract_Symptoms();
                        
                        break;

                    }
                }

            }
        }
        else
            MessageBox::Show("You didn't select any Disease !!", "Alert", MessageBoxButtons::OK, MessageBoxIcon::Error);
    }
    private: System::Void current_doctor_diseases_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void removed_diseases_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void removed_symps_listbox_SelectedIndexChanged(System::Object^ sender, System::EventArgs^ e) {
    }
    private: System::Void Alldiseases_combobox_SelectedValueChanged(System::Object^ sender, System::EventArgs^ e) {
        string selected_disease;
        if (Patients_of_chosen_disease_listbox->Visible) {
            Patients_of_chosen_disease_listbox->Items->Clear();
            MarshalString(Alldiseases_combobox->Text, selected_disease);
            for (int pat = 0; pat < index_allPatients; pat++) {
                for (int disease = 0; disease < allPatients[pat].Disease_History.size(); disease++) {
                    if (allPatients[pat].Disease_History[disease] == selected_disease) {
                        String^ newpat = gcnew String(allPatients[pat].patient_name.c_str());
                        Patients_of_chosen_disease_listbox->Items->Add(newpat);
                    }
                }
            }
        }
        else {
            Disease_docname_textbox->Clear();
            Disease_doc_phone_textbox->Clear();
            Disease_info_textbox->Clear();
            Disease_symps_listbox->Items->Clear();
            Disease_name_textbox->Clear();
            MarshalString(Alldiseases_combobox->Text, selected_disease);
            for (int disease = 0; disease < allDiseases.size(); disease++) {
                if (allDiseases[disease].name == selected_disease) {
                    Disease_docname_textbox->Text = gcnew String(allDiseases[disease].doc_name.c_str());
                    Disease_doc_phone_textbox->Text = gcnew String(allDiseases[disease].doc_phone.c_str());
                    Disease_info_textbox->Text = gcnew String(allDiseases[disease].info.c_str());
                    Disease_name_textbox->Text = gcnew String(allDiseases[disease].name.c_str());
                    for (int symp = 0; symp < allDiseases[disease].symps.size(); symp++) {
                        Disease_symps_listbox->Items->Add(gcnew String(allDiseases[disease].symps[symp].c_str()));

                    }
                }
            }
        }
    }
    private: System::Void button10_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void y_axis_picturebox_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void Recently_added_first_label_Click(System::Object^ sender, System::EventArgs^ e) {
    }
private: System::Void button11_Click(System::Object^ sender, System::EventArgs^ e) {
    timer6->Start();
}
private: System::Void timer6_Tick(System::Object^ sender, System::EventArgs^ e) {
    if (y_axis_picturebox->Height >= 400) {
        timer7->Start();
        timer6->Stop();

    }
    else {
        y_axis_picturebox->Show();
        y_axis_picturebox->Height += 10;
    }
}
private: System::Void timer7_Tick(System::Object^ sender, System::EventArgs^ e) {
    if (x_axis_picturebox->Width >= 523) {

        timer7->Stop();
        timer8->Start();
    }

    x_axis_picturebox->Show();
    x_axis_picturebox->Width += 10;

}
private: System::Void timer8_Tick(System::Object^ sender, System::EventArgs^ e) {
    if (most_front_picturebox->Height <= 0) {
        timer8->Stop();
        Most_value->Show();
        Most_name_label->Show();
    }
    if (most_front_picturebox->Height <= 300) {
        timer9->Start();
    }
    most_front_picturebox->Height -= 15;
}
private: System::Void timer9_Tick(System::Object^ sender, System::EventArgs^ e) {
    if (second_most_front_picturebox->Height <= 0) {
        timer9->Stop();
        second_most_value->Show();
        Second_Most_name_label->Show();
    }
    if (second_most_front_picturebox->Height <= 250) {
        timer10->Start();
    }
    second_most_front_picturebox->Height -= 15;
}
private: System::Void timer10_Tick(System::Object^ sender, System::EventArgs^ e) {
    if (third_most_front_picturebox->Height <=0) {
        timer10->Stop();
        third_most_value->Show();
        Third_Most_name_label->Show();
    }
    third_most_front_picturebox->Height -= 15;
}

private: System::Void feed_background_Click(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void pictureBox10_Click(System::Object^ sender, System::EventArgs^ e) {
    panel5->Show();
    feed_panel->Show();
    Feed();
    timer6->Start();
}
private: System::Void back_feed_picturebox_Click(System::Object^ sender, System::EventArgs^ e) {
    if (who_feed == "d") {
        feed_panel->Hide();
        Refresh();
    }
    else {
        feed_panel->Hide();
        panel5->Hide();
        Invalidate();
        Refresh();
        Invalidate();
    }
}
private: System::Void feed_panel_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
}
private: System::Void siticoneWinToggleSwith1_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
    
}








private: System::Void textBox6_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->KeyCode == Keys::Enter && panel5->Visible)
    {
        if (button4->Visible) {
            button4->PerformClick();
        }
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}
private: System::Void textBox5_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
    if (e->KeyCode == Keys::Enter && panel5->Visible)
    {
        if (button5->Visible) {
            button5->PerformClick();
        }
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}
private: System::Void siticoneWinToggleSwith1_CheckedChanged_1(System::Object^ sender, System::EventArgs^ e) {
    if (email_togglebutton->Checked) {
        send_email = 'T';
    }
    else {
        send_email = 'F';
    }
}
};
}
