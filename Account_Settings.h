#pragma once
#include <iostream>
#include <conio.h>
#include <stdio.h>   
#include<vector>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <signal.h> 
#include <functional>
#include "Camera_winform.h"
using namespace std;
namespace Project38 {
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
	using namespace System::Collections::Generic;
	/// <summary>
	/// Summary for Account_Settings
	/// </summary>
	public ref class Account_Settings : public System::Windows::Forms::Form
	{
		// your secondary/popup form's class




	private: System::Windows::Forms::TextBox^ Fullname_Textbox;
	private: System::Windows::Forms::TextBox^ Username_Textbox;

	private: System::Windows::Forms::GroupBox^ AccountGbox;
	private: System::Windows::Forms::Label^ Name_label;

	private: System::Windows::Forms::Label^ Phone;



	private: System::Windows::Forms::Label^ Username;


	private: System::Windows::Forms::Button^ No_pic_button;
	private: System::Windows::Forms::Button^ Browse_button;


	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Label^ label5;




	private: System::Windows::Forms::TextBox^ Phone_Textbox;




	private: System::Windows::Forms::GroupBox^ NotificationGbox;

	private: System::Windows::Forms::Label^ label10;
	private: System::Windows::Forms::GroupBox^ SecurityGbox;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;
	private: System::Windows::Forms::CheckBox^ Email_checkBox;

	private: System::Windows::Forms::Label^ label11;
	private: System::Windows::Forms::TextBox^ Email_Textbox;
	private: System::Windows::Forms::TextBox^ Password_Textbox;
	private: System::Windows::Forms::CheckBox^ step2_CheckBox;


	private: System::Windows::Forms::Button^ Save_button;


	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Button^ New_pic_button;


	private: System::Windows::Forms::TextBox^ step2_code_Textbox;

	private: System::Windows::Forms::Label^ step2_code_label;


	private: System::Windows::Forms::TextBox^ step2_phone_Textbox;

	private: System::Windows::Forms::Label^ step2_phone_label;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::Panel^ panel2;
	private: System::Windows::Forms::Label^ Hello_label;
	private: System::Windows::Forms::Button^ Account_button;
	private: System::Windows::Forms::Button^ Notification_button;


	private: System::Windows::Forms::Button^ Security_button;
	private: System::Windows::Forms::Button^ Logout_button;
	private: System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;
	private: System::Windows::Forms::Label^ Current_Tab_label;
	private: System::Windows::Forms::Button^ Send_code_button;












	public:
		int timer1_counter = 0;
		int timer1_counter2 = 0;
		int timer2_counter = 0;
		int timer2_counter2 = 0;
		static String^ Code;

		char who = 's';
	private: System::Windows::Forms::PictureBox^ Name_picturebox;
	private: System::Windows::Forms::PictureBox^ Name_pictureBox2;
	private: System::Windows::Forms::PictureBox^ Username_picturebox2;
	private: System::Windows::Forms::PictureBox^ Username_picturebox;
	private: System::Windows::Forms::PictureBox^ Phone_picturebox2;
	private: System::Windows::Forms::PictureBox^ pictureBox3;
	private: System::Windows::Forms::PictureBox^ Password_pictureBox;
	private: System::Windows::Forms::PictureBox^ pictureBox5;
	private: System::Windows::Forms::PictureBox^ VCODE_pictureBox;

	private: System::Windows::Forms::PictureBox^ pictureBox4;
	private: System::Windows::Forms::PictureBox^ Vphone_pictureBox;
	private: System::Windows::Forms::PictureBox^ pictureBox6;
	private: System::Windows::Forms::PictureBox^ Email_picturebox;


	private: System::Windows::Forms::PictureBox^ Phone_picturebox;





	public:

	public:
		List<PictureBox^>^ pics = gcnew List<PictureBox^>();
		
		List<Label^>^ labels = gcnew List<Label^>();
		
		String^ old_username;
		String^ old_phone;
		String^ old_email;
		String^ old_name;
	private: System::Windows::Forms::Label^ Username_error_label;
private: System::Windows::Forms::Label^ Fullname_error_label;
private: System::Windows::Forms::Label^ Phone_error_label;
private: System::Windows::Forms::TextBox^ textBox1;
private: System::Windows::Forms::Label^ Reenter;
private: System::Windows::Forms::PictureBox^ pictureBox7;
private: System::Windows::Forms::PictureBox^ pictureBox8;
private: System::Windows::Forms::Label^ Password_label_error;
private: System::Windows::Forms::Timer^ timer1;
private: System::Windows::Forms::Timer^ timer2;
private: System::Windows::Forms::Label^ Reenter_error_label;
private: System::Windows::Forms::Timer^ timer3;
	public:
		String^ old_pass;

		bool ufunC(function<bool(string)>func, string username) {
			return func(username);
		}
		bool changed = false;
		char s_key = '0';
		List<String^>^ EMAILS = gcnew List<String^>;
		List<String^>^ PHONES = gcnew List<String^>;
		List<String^>^ UNAMES = gcnew List<String^>;
		void Blue(PictureBox^ p, Label^ l) {
			l->ForeColor = Color::FromArgb(0, 102, 204);
			p->BackColor = Color::FromArgb(0, 102, 204);
		}
		void Green(PictureBox^ p, Label^ l) {
			l->ForeColor = Color::FromArgb(0,255, 0);
			p->BackColor = Color::FromArgb(0, 255, 0);
		}
		void Red(PictureBox^ p, Label^ l) {
			l->ForeColor = Color::FromArgb(255, 0, 0);
			p->BackColor = Color::FromArgb(255, 0, 0);
		}
		void Blacken(PictureBox^ p, Label^ l) {
			l->ForeColor = Color::FromArgb(0, 0, 0);
			p->BackColor = Color::FromArgb(0, 0, 0);
		}
		void Bluen(PictureBox^ p, Label^ l) {
			
			for (int i = 0; i < labels->Count; i++) {
				if (labels[i]->ForeColor != Color::FromArgb(0, 255, 0))
				Blacken(pics[i], labels[i]);
			}
			Blue(p, l);
		}


		char Logoutkey = '0';
		//Camera^ MyCamera = gcnew Camera();
		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		void save() {
			string username;
			MarshalString(Username_Textbox->Text, username);
			if (who == 'd') {
				string wow = "PICs\\Doctors\\" + username + ".jpg";
				String^ str3 = gcnew String(wow.c_str());
				if (pictureBox1->ImageLocation != "PICs\\guest.jpg") {
					if (System::IO::File::Exists(str3)) {
						System::IO::File::Delete(str3);
						pictureBox1->Image->Save(str3, ImageFormat::Jpeg);
					}
					else
						pictureBox1->Image->Save(str3, ImageFormat::Jpeg);
				}
				else {
					System::IO::File::Delete(str3);
				}
			}
			else if (who == 'p') {
				string wow = "PICs\\Patients\\" + username + ".jpg";
				String^ str3 = gcnew String(wow.c_str());
				if (pictureBox1->ImageLocation != "PICs\\guest.jpg") {
					if (System::IO::File::Exists(str3)) {
						System::IO::File::Delete(str3);
						pictureBox1->Image->Save(str3, ImageFormat::Jpeg);
					}
					else
						pictureBox1->Image->Save(str3, ImageFormat::Jpeg);
				}
				else {
					System::IO::File::Delete(str3);

				}

			}
		}
		String^ GetPass() {
			return Password_Textbox->Text;
		}
		String^ GetFullname() {
			return Fullname_Textbox->Text;
		}
		String^ GetUsername() {
			return Username_Textbox->Text;
		}
		String^ GetEmail() {
			return Email_Textbox->Text;
		}
		String^ GetPhone() {
			return Phone_Textbox->Text;
		}
		char Getsend_email() {
			if (Email_checkBox->Checked)
				return 'T';
			else
				return 'F';
		}
		bool logout() {
			if (Logoutkey == 'b' || Logoutkey == 'n')
				return true;
			else
				return false;
		}
		bool save_key() {
			if (Logoutkey == 'b' || Logoutkey == 'o')
				return true;
			else
				return false;
		}
		Account_Settings(void)
		{
			InitializeComponent();

			//
			//TODO: Add the constructor code here
			//
		}
		Account_Settings(string Fullname, string username, string pass, string email, string phone, char send_email, vector<string>allemails, vector<string>allphones, vector<string>allusernames)
		{
			InitializeComponent();
			for (int i = 0; i < allemails.size(); i++) {
				String^ u = gcnew String(allemails[i].c_str());
				EMAILS->Add(u);
			}
			for (int i = 0; i < allphones.size(); i++) {
				String^ u = gcnew String(allphones[i].c_str());
				PHONES->Add(u);
			}
			for (int i = 0; i < allusernames.size(); i++) {
				String^ u = gcnew String(allusernames[i].c_str());
				UNAMES->Add(u);
			}
			who = 'd';
			String^ name = gcnew String(Fullname.c_str());
			String^ uname = gcnew String(username.c_str());
			String^ p = gcnew String(pass.c_str());
			String^ Em = gcnew String(email.c_str());
			String^ pho = gcnew String(phone.c_str());
			Fullname_Textbox->Text = name;
			Hello_label->Text = "Hello Dr. " + name;
			Username_Textbox->Text = uname;
			Email_Textbox->Text = Em;
			Phone_Textbox->Text = pho;
			step2_phone_Textbox->Text = pho;
			Password_Textbox->Text = p;
			if (send_email == 'T') {
				Email_checkBox->Checked = true;
			}
			else {
				Email_checkBox->Checked = false;
			}

			string wow = "PICs\\Doctors\\" + username + ".jpg";
			String^ str3 = gcnew String(wow.c_str());
			if (System::IO::File::Exists(str3)) {
				pictureBox1->ImageLocation = str3;
				pictureBox2->ImageLocation = str3;
			}
			else {
				pictureBox1->ImageLocation = "PICs\\guest.jpg";
				pictureBox2->ImageLocation = "PICs\\guest.jpg";
			}
			GraphicsPath^ gp = gcnew GraphicsPath();
			gp->AddEllipse(pictureBox2->DisplayRectangle);
			pictureBox2->Region = gcnew System::Drawing::Region(gp);
			AccountGbox->Show();
			NotificationGbox->Hide();
			SecurityGbox->Hide();
			step2_phone_label->Hide();
			step2_phone_Textbox->Hide();
			Send_code_button->Hide();
			step2_code_label->Hide();
			step2_code_Textbox->Hide();
			Vphone_pictureBox->Hide();
			pictureBox4->Hide();
			pictureBox5->Hide();
			Send_code_button->Hide();
			VCODE_pictureBox->Hide();
			//panel3->Show();
			Password_Textbox->Text = p;
			//
			//TODO: Add the constructor code here
			//
		}
		Account_Settings(string Fullname, string username, string pass, string email, char gender, vector<string>allemails, vector<string>allphones, vector<string>allusernames)
		{
			InitializeComponent();
			for (int i = 0; i < allemails.size(); i++) {
				String^ u = gcnew String(allemails[i].c_str());
				EMAILS->Add(u);
			}
			for (int i = 0; i < allphones.size(); i++) {
				String^ u = gcnew String(allphones[i].c_str());
				PHONES->Add(u);
			}
			for (int i = 0; i < allusernames.size(); i++) {
				String^ u = gcnew String(allusernames[i].c_str());
				UNAMES->Add(u);
			}
			who = 'p';
			String^ name = gcnew String(Fullname.c_str());
			String^ uname = gcnew String(username.c_str());

			string OLD_username = username;
			String^ p = gcnew String(pass.c_str());
			String^ Em = gcnew String(email.c_str());
			Fullname_Textbox->Text = name;
			Username_Textbox->Text = uname;
			Email_Textbox->Text = Em;
			string wow = "PICs\\Patients\\" + username + ".jpg";
			String^ str3 = gcnew String(wow.c_str());
			if (System::IO::File::Exists(str3)) {
				pictureBox1->ImageLocation = str3;
				pictureBox2->ImageLocation = str3;
			}
			else {
				pictureBox1->ImageLocation = "PICs\\guest.jpg";
				pictureBox2->ImageLocation = "PICs\\guest.jpg";
			}
			GraphicsPath^ gp = gcnew GraphicsPath();
			gp->AddEllipse(pictureBox2->DisplayRectangle);
			pictureBox2->Region = gcnew System::Drawing::Region(gp);

			AccountGbox->Show();
			NotificationGbox->Hide();
			SecurityGbox->Hide();
			label11->Hide();
			Email_checkBox->Hide();
			step2_phone_label->Hide();
			step2_phone_Textbox->Hide();
			step2_code_label->Hide();
			step2_code_Textbox->Hide();
			Vphone_pictureBox->Hide();
			pictureBox4->Hide();
			pictureBox5->Hide();
			Send_code_button->Hide();
			VCODE_pictureBox->Hide();
			//Password_Textbox->Text = p;


			//
			//TODO: Add the constructor code here
			//
		}

		void Show_Account() {

		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Account_Settings()
		{
			if (components)
			{
				delete components;
			}
		}
private: System::ComponentModel::IContainer^ components;
protected:

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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Account_Settings::typeid));
			this->Fullname_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->Username_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->Phone_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->AccountGbox = (gcnew System::Windows::Forms::GroupBox());
			this->Phone_error_label = (gcnew System::Windows::Forms::Label());
			this->Fullname_error_label = (gcnew System::Windows::Forms::Label());
			this->Username_error_label = (gcnew System::Windows::Forms::Label());
			this->Phone = (gcnew System::Windows::Forms::Label());
			this->Phone_picturebox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Phone_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Browse_button = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Name_label = (gcnew System::Windows::Forms::Label());
			this->New_pic_button = (gcnew System::Windows::Forms::Button());
			this->No_pic_button = (gcnew System::Windows::Forms::Button());
			this->Name_pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Name_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->Username_picturebox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Username_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->NotificationGbox = (gcnew System::Windows::Forms::GroupBox());
			this->Email_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->pictureBox6 = (gcnew System::Windows::Forms::PictureBox());
			this->Email_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->Email_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->SecurityGbox = (gcnew System::Windows::Forms::GroupBox());
			this->Reenter_error_label = (gcnew System::Windows::Forms::Label());
			this->Password_label_error = (gcnew System::Windows::Forms::Label());
			this->step2_code_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->step2_code_label = (gcnew System::Windows::Forms::Label());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->VCODE_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->step2_phone_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->step2_phone_label = (gcnew System::Windows::Forms::Label());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->Vphone_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Password_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->pictureBox3 = (gcnew System::Windows::Forms::PictureBox());
			this->Password_pictureBox = (gcnew System::Windows::Forms::PictureBox());
			this->Send_code_button = (gcnew System::Windows::Forms::Button());
			this->step2_CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->Reenter = (gcnew System::Windows::Forms::Label());
			this->pictureBox7 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox8 = (gcnew System::Windows::Forms::PictureBox());
			this->Save_button = (gcnew System::Windows::Forms::Button());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->Logout_button = (gcnew System::Windows::Forms::Button());
			this->Notification_button = (gcnew System::Windows::Forms::Button());
			this->Security_button = (gcnew System::Windows::Forms::Button());
			this->Account_button = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->Hello_label = (gcnew System::Windows::Forms::Label());
			this->Current_Tab_label = (gcnew System::Windows::Forms::Label());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->timer3 = (gcnew System::Windows::Forms::Timer(this->components));
			this->AccountGbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_picturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox))->BeginInit();
			this->NotificationGbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Email_picturebox))->BeginInit();
			this->SecurityGbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCODE_pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vphone_pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Password_pictureBox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel1->SuspendLayout();
			this->tableLayoutPanel1->SuspendLayout();
			this->panel2->SuspendLayout();
			this->SuspendLayout();
			// 
			// Fullname_Textbox
			// 
			this->Fullname_Textbox->BackColor = System::Drawing::Color::White;
			this->Fullname_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Fullname_Textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Fullname_Textbox->Location = System::Drawing::Point(32, 177);
			this->Fullname_Textbox->Name = L"Fullname_Textbox";
			this->Fullname_Textbox->Size = System::Drawing::Size(325, 27);
			this->Fullname_Textbox->TabIndex = 0;
			this->Fullname_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::Fullname_Textbox_MouseClick);
			this->Fullname_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Fullname_Textbox_TextChanged);
			this->Fullname_Textbox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Account_Settings::Fullname_Textbox_Validating);
			// 
			// Username_Textbox
			// 
			this->Username_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Username_Textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username_Textbox->Location = System::Drawing::Point(30, 266);
			this->Username_Textbox->Name = L"Username_Textbox";
			this->Username_Textbox->Size = System::Drawing::Size(325, 27);
			this->Username_Textbox->TabIndex = 1;
			this->Username_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::Username_Textbox_MouseClick);
			this->Username_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Username_Textbox_TextChanged);
			this->Username_Textbox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Account_Settings::Username_Textbox_Validating);
			// 
			// Phone_Textbox
			// 
			this->Phone_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Phone_Textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Phone_Textbox->Location = System::Drawing::Point(31, 357);
			this->Phone_Textbox->Name = L"Phone_Textbox";
			this->Phone_Textbox->Size = System::Drawing::Size(324, 27);
			this->Phone_Textbox->TabIndex = 3;
			this->Phone_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::Phone_Textbox_MouseClick);
			this->Phone_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Phone_Textbox_TextChanged);
			this->Phone_Textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account_Settings::Phone_Textbox_KeyPress);
			this->Phone_Textbox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Account_Settings::Phone_Textbox_Validating);
			// 
			// AccountGbox
			// 
			this->AccountGbox->BackColor = System::Drawing::Color::White;
			this->AccountGbox->Controls->Add(this->Phone_error_label);
			this->AccountGbox->Controls->Add(this->Fullname_error_label);
			this->AccountGbox->Controls->Add(this->Username_error_label);
			this->AccountGbox->Controls->Add(this->Phone);
			this->AccountGbox->Controls->Add(this->Phone_Textbox);
			this->AccountGbox->Controls->Add(this->Phone_picturebox2);
			this->AccountGbox->Controls->Add(this->Phone_picturebox);
			this->AccountGbox->Controls->Add(this->Username_Textbox);
			this->AccountGbox->Controls->Add(this->Username);
			this->AccountGbox->Controls->Add(this->pictureBox1);
			this->AccountGbox->Controls->Add(this->Browse_button);
			this->AccountGbox->Controls->Add(this->label5);
			this->AccountGbox->Controls->Add(this->Name_label);
			this->AccountGbox->Controls->Add(this->Fullname_Textbox);
			this->AccountGbox->Controls->Add(this->New_pic_button);
			this->AccountGbox->Controls->Add(this->No_pic_button);
			this->AccountGbox->Controls->Add(this->Name_pictureBox2);
			this->AccountGbox->Controls->Add(this->Name_picturebox);
			this->AccountGbox->Controls->Add(this->Username_picturebox2);
			this->AccountGbox->Controls->Add(this->Username_picturebox);
			this->AccountGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AccountGbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AccountGbox->Location = System::Drawing::Point(286, 0);
			this->AccountGbox->Name = L"AccountGbox";
			this->AccountGbox->Size = System::Drawing::Size(825, 745);
			this->AccountGbox->TabIndex = 4;
			this->AccountGbox->TabStop = false;
			this->AccountGbox->Enter += gcnew System::EventHandler(this, &Account_Settings::AccountGbox_Enter);
			// 
			// Phone_error_label
			// 
			this->Phone_error_label->AutoSize = true;
			this->Phone_error_label->Location = System::Drawing::Point(398, 366);
			this->Phone_error_label->Name = L"Phone_error_label";
			this->Phone_error_label->Size = System::Drawing::Size(43, 17);
			this->Phone_error_label->TabIndex = 21;
			this->Phone_error_label->Text = L"label1";
			// 
			// Fullname_error_label
			// 
			this->Fullname_error_label->AutoSize = true;
			this->Fullname_error_label->Location = System::Drawing::Point(398, 186);
			this->Fullname_error_label->Name = L"Fullname_error_label";
			this->Fullname_error_label->Size = System::Drawing::Size(43, 17);
			this->Fullname_error_label->TabIndex = 20;
			this->Fullname_error_label->Text = L"label1";
			// 
			// Username_error_label
			// 
			this->Username_error_label->AutoSize = true;
			this->Username_error_label->Location = System::Drawing::Point(401, 270);
			this->Username_error_label->Name = L"Username_error_label";
			this->Username_error_label->Size = System::Drawing::Size(43, 17);
			this->Username_error_label->TabIndex = 19;
			this->Username_error_label->Text = L"label1";
			// 
			// Phone
			// 
			this->Phone->AutoSize = true;
			this->Phone->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13));
			this->Phone->Location = System::Drawing::Point(58, 327);
			this->Phone->Name = L"Phone";
			this->Phone->Size = System::Drawing::Size(82, 30);
			this->Phone->TabIndex = 7;
			this->Phone->Text = L"Phone:";
			this->Phone->Click += gcnew System::EventHandler(this, &Account_Settings::label4_Click);
			// 
			// Phone_picturebox2
			// 
			this->Phone_picturebox2->Location = System::Drawing::Point(29, 350);
			this->Phone_picturebox2->Name = L"Phone_picturebox2";
			this->Phone_picturebox2->Size = System::Drawing::Size(328, 45);
			this->Phone_picturebox2->TabIndex = 18;
			this->Phone_picturebox2->TabStop = false;
			// 
			// Phone_picturebox
			// 
			this->Phone_picturebox->BackColor = System::Drawing::Color::Black;
			this->Phone_picturebox->Location = System::Drawing::Point(27, 346);
			this->Phone_picturebox->Name = L"Phone_picturebox";
			this->Phone_picturebox->Size = System::Drawing::Size(333, 53);
			this->Phone_picturebox->TabIndex = 17;
			this->Phone_picturebox->TabStop = false;
			// 
			// Username
			// 
			this->Username->AutoSize = true;
			this->Username->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13, System::Drawing::FontStyle::Bold));
			this->Username->Location = System::Drawing::Point(55, 232);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(117, 30);
			this->Username->TabIndex = 5;
			this->Username->Text = L"Username:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(273, 420);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(139, 155);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// Browse_button
			// 
			this->Browse_button->Location = System::Drawing::Point(462, 442);
			this->Browse_button->Name = L"Browse_button";
			this->Browse_button->Size = System::Drawing::Size(91, 39);
			this->Browse_button->TabIndex = 10;
			this->Browse_button->Text = L" Browse";
			this->Browse_button->UseVisualStyleBackColor = true;
			this->Browse_button->Click += gcnew System::EventHandler(this, &Account_Settings::Browse_button_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label5->Location = System::Drawing::Point(44, 484);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(219, 41);
			this->label5->TabIndex = 8;
			this->label5->Text = L" Profile picture";
			// 
			// Name_label
			// 
			this->Name_label->AutoSize = true;
			this->Name_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13));
			this->Name_label->Location = System::Drawing::Point(58, 143);
			this->Name_label->Name = L"Name_label";
			this->Name_label->Size = System::Drawing::Size(77, 30);
			this->Name_label->TabIndex = 4;
			this->Name_label->Text = L"Name:";
			// 
			// New_pic_button
			// 
			this->New_pic_button->Location = System::Drawing::Point(578, 471);
			this->New_pic_button->Name = L"New_pic_button";
			this->New_pic_button->Size = System::Drawing::Size(91, 54);
			this->New_pic_button->TabIndex = 12;
			this->New_pic_button->Text = L" Take a New Picture";
			this->New_pic_button->UseVisualStyleBackColor = true;
			this->New_pic_button->Click += gcnew System::EventHandler(this, &Account_Settings::New_pic_button_Click);
			// 
			// No_pic_button
			// 
			this->No_pic_button->Location = System::Drawing::Point(462, 502);
			this->No_pic_button->Name = L"No_pic_button";
			this->No_pic_button->Size = System::Drawing::Size(91, 48);
			this->No_pic_button->TabIndex = 11;
			this->No_pic_button->Text = L" No Profile picture";
			this->No_pic_button->UseVisualStyleBackColor = true;
			this->No_pic_button->Click += gcnew System::EventHandler(this, &Account_Settings::No_pic_button_Click);
			// 
			// Name_pictureBox2
			// 
			this->Name_pictureBox2->Location = System::Drawing::Point(30, 168);
			this->Name_pictureBox2->Name = L"Name_pictureBox2";
			this->Name_pictureBox2->Size = System::Drawing::Size(328, 45);
			this->Name_pictureBox2->TabIndex = 14;
			this->Name_pictureBox2->TabStop = false;
			this->Name_pictureBox2->Click += gcnew System::EventHandler(this, &Account_Settings::Name_pictureBox2_Click);
			// 
			// Name_picturebox
			// 
			this->Name_picturebox->BackColor = System::Drawing::Color::Black;
			this->Name_picturebox->Location = System::Drawing::Point(28, 164);
			this->Name_picturebox->Name = L"Name_picturebox";
			this->Name_picturebox->Size = System::Drawing::Size(333, 53);
			this->Name_picturebox->TabIndex = 13;
			this->Name_picturebox->TabStop = false;
			this->Name_picturebox->Click += gcnew System::EventHandler(this, &Account_Settings::pictureBox3_Click);
			// 
			// Username_picturebox2
			// 
			this->Username_picturebox2->Location = System::Drawing::Point(29, 259);
			this->Username_picturebox2->Name = L"Username_picturebox2";
			this->Username_picturebox2->Size = System::Drawing::Size(328, 45);
			this->Username_picturebox2->TabIndex = 16;
			this->Username_picturebox2->TabStop = false;
			// 
			// Username_picturebox
			// 
			this->Username_picturebox->BackColor = System::Drawing::Color::Black;
			this->Username_picturebox->Location = System::Drawing::Point(27, 255);
			this->Username_picturebox->Name = L"Username_picturebox";
			this->Username_picturebox->Size = System::Drawing::Size(333, 53);
			this->Username_picturebox->TabIndex = 15;
			this->Username_picturebox->TabStop = false;
			// 
			// NotificationGbox
			// 
			this->NotificationGbox->BackColor = System::Drawing::Color::White;
			this->NotificationGbox->Controls->Add(this->Email_Textbox);
			this->NotificationGbox->Controls->Add(this->label10);
			this->NotificationGbox->Controls->Add(this->pictureBox6);
			this->NotificationGbox->Controls->Add(this->Email_picturebox);
			this->NotificationGbox->Controls->Add(this->label11);
			this->NotificationGbox->Controls->Add(this->Email_checkBox);
			this->NotificationGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NotificationGbox->Location = System::Drawing::Point(286, 0);
			this->NotificationGbox->Name = L"NotificationGbox";
			this->NotificationGbox->Size = System::Drawing::Size(781, 739);
			this->NotificationGbox->TabIndex = 7;
			this->NotificationGbox->TabStop = false;
			// 
			// Email_Textbox
			// 
			this->Email_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Email_Textbox->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->Email_Textbox->Location = System::Drawing::Point(65, 270);
			this->Email_Textbox->Name = L"Email_Textbox";
			this->Email_Textbox->Size = System::Drawing::Size(326, 25);
			this->Email_Textbox->TabIndex = 7;
			this->Email_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::Email_Textbox_MouseClick);
			this->Email_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Email_Textbox_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13));
			this->label10->Location = System::Drawing::Point(78, 239);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(74, 26);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Email:";
			// 
			// pictureBox6
			// 
			this->pictureBox6->Location = System::Drawing::Point(64, 259);
			this->pictureBox6->Name = L"pictureBox6";
			this->pictureBox6->Size = System::Drawing::Size(328, 45);
			this->pictureBox6->TabIndex = 18;
			this->pictureBox6->TabStop = false;
			// 
			// Email_picturebox
			// 
			this->Email_picturebox->BackColor = System::Drawing::Color::Black;
			this->Email_picturebox->Location = System::Drawing::Point(61, 255);
			this->Email_picturebox->Name = L"Email_picturebox";
			this->Email_picturebox->Size = System::Drawing::Size(334, 53);
			this->Email_picturebox->TabIndex = 17;
			this->Email_picturebox->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(46, 336);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(399, 25);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Receive an email for each patient diagnosed ";
			// 
			// Email_checkBox
			// 
			this->Email_checkBox->AutoSize = true;
			this->Email_checkBox->Location = System::Drawing::Point(486, 340);
			this->Email_checkBox->Name = L"Email_checkBox";
			this->Email_checkBox->Size = System::Drawing::Size(18, 17);
			this->Email_checkBox->TabIndex = 9;
			this->Email_checkBox->UseVisualStyleBackColor = true;
			this->Email_checkBox->CheckedChanged += gcnew System::EventHandler(this, &Account_Settings::Email_checkBox_CheckedChanged);
			// 
			// SecurityGbox
			// 
			this->SecurityGbox->BackColor = System::Drawing::Color::White;
			this->SecurityGbox->Controls->Add(this->Reenter_error_label);
			this->SecurityGbox->Controls->Add(this->Password_label_error);
			this->SecurityGbox->Controls->Add(this->step2_code_Textbox);
			this->SecurityGbox->Controls->Add(this->step2_code_label);
			this->SecurityGbox->Controls->Add(this->pictureBox5);
			this->SecurityGbox->Controls->Add(this->VCODE_pictureBox);
			this->SecurityGbox->Controls->Add(this->step2_phone_Textbox);
			this->SecurityGbox->Controls->Add(this->step2_phone_label);
			this->SecurityGbox->Controls->Add(this->pictureBox4);
			this->SecurityGbox->Controls->Add(this->Vphone_pictureBox);
			this->SecurityGbox->Controls->Add(this->Password_Textbox);
			this->SecurityGbox->Controls->Add(this->label9);
			this->SecurityGbox->Controls->Add(this->pictureBox3);
			this->SecurityGbox->Controls->Add(this->Password_pictureBox);
			this->SecurityGbox->Controls->Add(this->Send_code_button);
			this->SecurityGbox->Controls->Add(this->step2_CheckBox);
			this->SecurityGbox->Controls->Add(this->label8);
			this->SecurityGbox->Controls->Add(this->textBox1);
			this->SecurityGbox->Controls->Add(this->Reenter);
			this->SecurityGbox->Controls->Add(this->pictureBox7);
			this->SecurityGbox->Controls->Add(this->pictureBox8);
			this->SecurityGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SecurityGbox->Location = System::Drawing::Point(286, 0);
			this->SecurityGbox->Name = L"SecurityGbox";
			this->SecurityGbox->Size = System::Drawing::Size(770, 822);
			this->SecurityGbox->TabIndex = 8;
			this->SecurityGbox->TabStop = false;
			// 
			// Reenter_error_label
			// 
			this->Reenter_error_label->AutoSize = true;
			this->Reenter_error_label->Location = System::Drawing::Point(402, 244);
			this->Reenter_error_label->Name = L"Reenter_error_label";
			this->Reenter_error_label->Size = System::Drawing::Size(0, 17);
			this->Reenter_error_label->TabIndex = 28;
			// 
			// Password_label_error
			// 
			this->Password_label_error->AutoSize = true;
			this->Password_label_error->Location = System::Drawing::Point(402, 243);
			this->Password_label_error->Name = L"Password_label_error";
			this->Password_label_error->Size = System::Drawing::Size(0, 17);
			this->Password_label_error->TabIndex = 27;
			// 
			// step2_code_Textbox
			// 
			this->step2_code_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->step2_code_Textbox->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->step2_code_Textbox->Location = System::Drawing::Point(41, 450);
			this->step2_code_Textbox->Name = L"step2_code_Textbox";
			this->step2_code_Textbox->Size = System::Drawing::Size(326, 25);
			this->step2_code_Textbox->TabIndex = 15;
			this->step2_code_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::step2_code_Textbox_MouseClick);
			this->step2_code_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::step2_code_Textbox_TextChanged);
			// 
			// step2_code_label
			// 
			this->step2_code_label->AutoSize = true;
			this->step2_code_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13));
			this->step2_code_label->Location = System::Drawing::Point(55, 413);
			this->step2_code_label->Name = L"step2_code_label";
			this->step2_code_label->Size = System::Drawing::Size(190, 30);
			this->step2_code_label->TabIndex = 14;
			this->step2_code_label->Text = L"Verification Code:";
			// 
			// pictureBox5
			// 
			this->pictureBox5->Location = System::Drawing::Point(40, 436);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(328, 45);
			this->pictureBox5->TabIndex = 22;
			this->pictureBox5->TabStop = false;
			// 
			// VCODE_pictureBox
			// 
			this->VCODE_pictureBox->BackColor = System::Drawing::Color::Black;
			this->VCODE_pictureBox->Location = System::Drawing::Point(37, 432);
			this->VCODE_pictureBox->Name = L"VCODE_pictureBox";
			this->VCODE_pictureBox->Size = System::Drawing::Size(334, 53);
			this->VCODE_pictureBox->TabIndex = 21;
			this->VCODE_pictureBox->TabStop = false;
			// 
			// step2_phone_Textbox
			// 
			this->step2_phone_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->step2_phone_Textbox->Font = (gcnew System::Drawing::Font(L"Tahoma", 12));
			this->step2_phone_Textbox->Location = System::Drawing::Point(38, 360);
			this->step2_phone_Textbox->Name = L"step2_phone_Textbox";
			this->step2_phone_Textbox->Size = System::Drawing::Size(326, 25);
			this->step2_phone_Textbox->TabIndex = 13;
			this->step2_phone_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::step2_phone_Textbox_MouseClick);
			this->step2_phone_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::step2_phone_Textbox_TextChanged);
			this->step2_phone_Textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account_Settings::step2_phone_Textbox_KeyPress);
			// 
			// step2_phone_label
			// 
			this->step2_phone_label->AutoSize = true;
			this->step2_phone_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13));
			this->step2_phone_label->Location = System::Drawing::Point(55, 326);
			this->step2_phone_label->Name = L"step2_phone_label";
			this->step2_phone_label->Size = System::Drawing::Size(82, 30);
			this->step2_phone_label->TabIndex = 12;
			this->step2_phone_label->Text = L"Phone:";
			// 
			// pictureBox4
			// 
			this->pictureBox4->Location = System::Drawing::Point(37, 347);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(328, 45);
			this->pictureBox4->TabIndex = 20;
			this->pictureBox4->TabStop = false;
			// 
			// Vphone_pictureBox
			// 
			this->Vphone_pictureBox->BackColor = System::Drawing::Color::Black;
			this->Vphone_pictureBox->Location = System::Drawing::Point(34, 343);
			this->Vphone_pictureBox->Name = L"Vphone_pictureBox";
			this->Vphone_pictureBox->Size = System::Drawing::Size(334, 53);
			this->Vphone_pictureBox->TabIndex = 19;
			this->Vphone_pictureBox->TabStop = false;
			// 
			// Password_Textbox
			// 
			this->Password_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Password_Textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->Password_Textbox->Location = System::Drawing::Point(41, 239);
			this->Password_Textbox->Name = L"Password_Textbox";
			this->Password_Textbox->ShortcutsEnabled = false;
			this->Password_Textbox->Size = System::Drawing::Size(326, 23);
			this->Password_Textbox->TabIndex = 8;
			this->Password_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::Password_Textbox_MouseClick);
			this->Password_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Password_Textbox_TextChanged);
			this->Password_Textbox->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Account_Settings::Password_Textbox_Validating);
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13));
			this->label9->Location = System::Drawing::Point(55, 207);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(110, 30);
			this->label9->TabIndex = 4;
			this->label9->Text = L"Password:";
			// 
			// pictureBox3
			// 
			this->pictureBox3->Location = System::Drawing::Point(40, 229);
			this->pictureBox3->Name = L"pictureBox3";
			this->pictureBox3->Size = System::Drawing::Size(328, 45);
			this->pictureBox3->TabIndex = 18;
			this->pictureBox3->TabStop = false;
			// 
			// Password_pictureBox
			// 
			this->Password_pictureBox->BackColor = System::Drawing::Color::Black;
			this->Password_pictureBox->Location = System::Drawing::Point(37, 225);
			this->Password_pictureBox->Name = L"Password_pictureBox";
			this->Password_pictureBox->Size = System::Drawing::Size(334, 53);
			this->Password_pictureBox->TabIndex = 17;
			this->Password_pictureBox->TabStop = false;
			// 
			// Send_code_button
			// 
			this->Send_code_button->Location = System::Drawing::Point(396, 357);
			this->Send_code_button->Name = L"Send_code_button";
			this->Send_code_button->Size = System::Drawing::Size(66, 23);
			this->Send_code_button->TabIndex = 16;
			this->Send_code_button->Text = L"Send";
			this->Send_code_button->UseVisualStyleBackColor = true;
			this->Send_code_button->Click += gcnew System::EventHandler(this, &Account_Settings::Send_code_button_Click);
			// 
			// step2_CheckBox
			// 
			this->step2_CheckBox->AutoSize = true;
			this->step2_CheckBox->Location = System::Drawing::Point(423, 302);
			this->step2_CheckBox->Name = L"step2_CheckBox";
			this->step2_CheckBox->Size = System::Drawing::Size(18, 17);
			this->step2_CheckBox->TabIndex = 10;
			this->step2_CheckBox->UseVisualStyleBackColor = true;
			this->step2_CheckBox->CheckedChanged += gcnew System::EventHandler(this, &Account_Settings::step2_CheckBox_CheckedChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label8->Location = System::Drawing::Point(24, 286);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(322, 41);
			this->label8->TabIndex = 6;
			this->label8->Text = L" For 2 step verification";
			// 
			// textBox1
			// 
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12));
			this->textBox1->Location = System::Drawing::Point(42, 239);
			this->textBox1->Name = L"textBox1";
			this->textBox1->ShortcutsEnabled = false;
			this->textBox1->Size = System::Drawing::Size(326, 23);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &Account_Settings::textBox1_TextChanged);
			this->textBox1->Validating += gcnew System::ComponentModel::CancelEventHandler(this, &Account_Settings::textBox1_Validating);
			// 
			// Reenter
			// 
			this->Reenter->AutoSize = true;
			this->Reenter->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 13));
			this->Reenter->Location = System::Drawing::Point(56, 207);
			this->Reenter->Name = L"Reenter";
			this->Reenter->Size = System::Drawing::Size(194, 30);
			this->Reenter->TabIndex = 23;
			this->Reenter->Text = L"Reenter Password:";
			// 
			// pictureBox7
			// 
			this->pictureBox7->Location = System::Drawing::Point(41, 229);
			this->pictureBox7->Name = L"pictureBox7";
			this->pictureBox7->Size = System::Drawing::Size(328, 45);
			this->pictureBox7->TabIndex = 26;
			this->pictureBox7->TabStop = false;
			// 
			// pictureBox8
			// 
			this->pictureBox8->BackColor = System::Drawing::Color::Black;
			this->pictureBox8->Location = System::Drawing::Point(38, 225);
			this->pictureBox8->Name = L"pictureBox8";
			this->pictureBox8->Size = System::Drawing::Size(334, 53);
			this->pictureBox8->TabIndex = 25;
			this->pictureBox8->TabStop = false;
			// 
			// Save_button
			// 
			this->Save_button->BackColor = System::Drawing::SystemColors::HotTrack;
			this->Save_button->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Save_button->FlatAppearance->BorderSize = 0;
			this->Save_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Save_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Save_button->ForeColor = System::Drawing::Color::White;
			this->Save_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Save_button.Image")));
			this->Save_button->Location = System::Drawing::Point(145, 3);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(137, 179);
			this->Save_button->TabIndex = 10;
			this->Save_button->Text = L" Save";
			this->Save_button->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Save_button->UseVisualStyleBackColor = false;
			this->Save_button->Click += gcnew System::EventHandler(this, &Account_Settings::Save_button_Click);
			this->Save_button->MouseLeave += gcnew System::EventHandler(this, &Account_Settings::Save_button_MouseLeave);
			this->Save_button->MouseHover += gcnew System::EventHandler(this, &Account_Settings::Save_button_MouseHover);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(69, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(102, 119);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 12;
			this->pictureBox2->TabStop = false;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->tableLayoutPanel1);
			this->panel1->Controls->Add(this->Notification_button);
			this->panel1->Controls->Add(this->Security_button);
			this->panel1->Controls->Add(this->Account_button);
			this->panel1->Controls->Add(this->panel2);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(288, 715);
			this->panel1->TabIndex = 13;
			// 
			// tableLayoutPanel1
			// 
			this->tableLayoutPanel1->BackColor = System::Drawing::SystemColors::HotTrack;
			this->tableLayoutPanel1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->tableLayoutPanel1->ColumnCount = 2;
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(System::Windows::Forms::SizeType::Percent,
				50)));
			this->tableLayoutPanel1->Controls->Add(this->Logout_button, 0, 0);
			this->tableLayoutPanel1->Controls->Add(this->Save_button, 1, 0);
			this->tableLayoutPanel1->Location = System::Drawing::Point(3, 527);
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			this->tableLayoutPanel1->RowCount = 1;
			this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle(System::Windows::Forms::SizeType::Percent, 50)));
			this->tableLayoutPanel1->Size = System::Drawing::Size(285, 185);
			this->tableLayoutPanel1->TabIndex = 14;
			// 
			// Logout_button
			// 
			this->Logout_button->BackColor = System::Drawing::SystemColors::HotTrack;
			this->Logout_button->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Logout_button->FlatAppearance->BorderSize = 0;
			this->Logout_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Logout_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Logout_button->ForeColor = System::Drawing::Color::White;
			this->Logout_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logout_button.Image")));
			this->Logout_button->Location = System::Drawing::Point(3, 3);
			this->Logout_button->Name = L"Logout_button";
			this->Logout_button->Size = System::Drawing::Size(136, 179);
			this->Logout_button->TabIndex = 11;
			this->Logout_button->Text = L" Logout";
			this->Logout_button->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->Logout_button->UseVisualStyleBackColor = false;
			this->Logout_button->Click += gcnew System::EventHandler(this, &Account_Settings::Logout_button_Click);
			this->Logout_button->MouseLeave += gcnew System::EventHandler(this, &Account_Settings::Logout_button_MouseLeave);
			this->Logout_button->MouseHover += gcnew System::EventHandler(this, &Account_Settings::Logout_button_MouseHover);
			// 
			// Notification_button
			// 
			this->Notification_button->Dock = System::Windows::Forms::DockStyle::Top;
			this->Notification_button->FlatAppearance->BorderSize = 0;
			this->Notification_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Notification_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Notification_button->ForeColor = System::Drawing::Color::White;
			this->Notification_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Notification_button.Image")));
			this->Notification_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Notification_button->Location = System::Drawing::Point(0, 415);
			this->Notification_button->Name = L"Notification_button";
			this->Notification_button->Size = System::Drawing::Size(288, 119);
			this->Notification_button->TabIndex = 16;
			this->Notification_button->Text = L"       Notification";
			this->Notification_button->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Notification_button->UseVisualStyleBackColor = true;
			this->Notification_button->Click += gcnew System::EventHandler(this, &Account_Settings::Notification_button_Click);
			this->Notification_button->MouseLeave += gcnew System::EventHandler(this, &Account_Settings::Notification_button_MouseLeave);
			this->Notification_button->MouseHover += gcnew System::EventHandler(this, &Account_Settings::Notification_button_MouseHover);
			// 
			// Security_button
			// 
			this->Security_button->Dock = System::Windows::Forms::DockStyle::Top;
			this->Security_button->FlatAppearance->BorderSize = 0;
			this->Security_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Security_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Security_button->ForeColor = System::Drawing::Color::White;
			this->Security_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Security_button.Image")));
			this->Security_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Security_button->Location = System::Drawing::Point(0, 296);
			this->Security_button->Name = L"Security_button";
			this->Security_button->Size = System::Drawing::Size(288, 119);
			this->Security_button->TabIndex = 15;
			this->Security_button->Text = L"    Security";
			this->Security_button->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Security_button->UseVisualStyleBackColor = true;
			this->Security_button->Click += gcnew System::EventHandler(this, &Account_Settings::Security_button_Click);
			this->Security_button->MouseLeave += gcnew System::EventHandler(this, &Account_Settings::Security_button_MouseLeave);
			this->Security_button->MouseHover += gcnew System::EventHandler(this, &Account_Settings::Security_button_MouseHover);
			// 
			// Account_button
			// 
			this->Account_button->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->Account_button->Dock = System::Windows::Forms::DockStyle::Top;
			this->Account_button->FlatAppearance->BorderSize = 0;
			this->Account_button->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->Account_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Account_button->ForeColor = System::Drawing::Color::White;
			this->Account_button->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Account_button.Image")));
			this->Account_button->ImageAlign = System::Drawing::ContentAlignment::MiddleLeft;
			this->Account_button->Location = System::Drawing::Point(0, 177);
			this->Account_button->Name = L"Account_button";
			this->Account_button->Size = System::Drawing::Size(288, 119);
			this->Account_button->TabIndex = 14;
			this->Account_button->Text = L"     Account";
			this->Account_button->TextImageRelation = System::Windows::Forms::TextImageRelation::ImageBeforeText;
			this->Account_button->UseVisualStyleBackColor = true;
			this->Account_button->Click += gcnew System::EventHandler(this, &Account_Settings::Account_button_Click);
			this->Account_button->MouseLeave += gcnew System::EventHandler(this, &Account_Settings::Account_button_MouseLeave);
			this->Account_button->MouseHover += gcnew System::EventHandler(this, &Account_Settings::Account_button_MouseHover);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->Hello_label);
			this->panel2->Controls->Add(this->pictureBox2);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(0, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(288, 177);
			this->panel2->TabIndex = 0;
			// 
			// Hello_label
			// 
			this->Hello_label->AutoSize = true;
			this->Hello_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hello_label->Location = System::Drawing::Point(38, 145);
			this->Hello_label->Name = L"Hello_label";
			this->Hello_label->Size = System::Drawing::Size(59, 20);
			this->Hello_label->TabIndex = 14;
			this->Hello_label->Text = L"label3";
			this->Hello_label->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Current_Tab_label
			// 
			this->Current_Tab_label->AutoSize = true;
			this->Current_Tab_label->BackColor = System::Drawing::Color::White;
			this->Current_Tab_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 22.2F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Current_Tab_label->Location = System::Drawing::Point(606, 12);
			this->Current_Tab_label->Name = L"Current_Tab_label";
			this->Current_Tab_label->Size = System::Drawing::Size(154, 42);
			this->Current_Tab_label->TabIndex = 0;
			this->Current_Tab_label->Text = L"Account";
			// 
			// timer1
			// 
			this->timer1->Tick += gcnew System::EventHandler(this, &Account_Settings::timer1_Tick);
			// 
			// timer2
			// 
			this->timer2->Tick += gcnew System::EventHandler(this, &Account_Settings::timer2_Tick);
			// 
			// timer3
			// 
			this->timer3->Tick += gcnew System::EventHandler(this, &Account_Settings::timer3_Tick);
			// 
			// Account_Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ClientSize = System::Drawing::Size(1054, 715);
			this->Controls->Add(this->Current_Tab_label);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->SecurityGbox);
			this->Controls->Add(this->NotificationGbox);
			this->Controls->Add(this->AccountGbox);
			this->Name = L"Account_Settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Account_Settings";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Account_Settings::Account_Settings_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Account_Settings::Account_Settings_Load);
			this->AccountGbox->ResumeLayout(false);
			this->AccountGbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_picturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox))->EndInit();
			this->NotificationGbox->ResumeLayout(false);
			this->NotificationGbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox6))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Email_picturebox))->EndInit();
			this->SecurityGbox->ResumeLayout(false);
			this->SecurityGbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VCODE_pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Vphone_pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox3))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Password_pictureBox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox7))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox8))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	public:
		int curr_loc;
	private: System::Void Account_Settings_Load(System::Object^ sender, System::EventArgs^ e) {
		
		curr_loc= Password_Textbox->Location.Y;
		Show_Account();
		changed = false;
		old_username = Username_Textbox->Text;
		old_phone = Phone_Textbox->Text;
		old_email = Email_Textbox->Text;
		old_name = Fullname_Textbox->Text;
		old_pass = Password_Textbox->Text;


		labels->Add(label9);
		labels->Add(Name_label);
		labels->Add(Phone);
		labels->Add(Username);
		labels->Add(label10);
		labels->Add(step2_phone_label);
		labels->Add(step2_code_label);
		labels->Add(Reenter);
		
		pics->Add(Password_pictureBox);
		pics->Add(Name_picturebox);
		pics->Add(Phone_picturebox);
		pics->Add(Username_picturebox);
		pics->Add(Email_picturebox);
		pics->Add(VCODE_pictureBox);
		pics->Add(Vphone_pictureBox);
		pics->Add(pictureBox8);

		Reenter->Hide();
		pictureBox7->Hide();
		pictureBox8->Hide();
		textBox1->Hide();
		Username_error_label->Hide();
		Fullname_error_label->Hide();
		Password_label_error->Hide();
		Reenter_error_label->Hide();
		Phone_error_label->Hide();
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Phone_Textbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char ch = e->KeyChar;
		if (!isdigit(ch) && ch != 8)
		{
			e->Handled = true;
		}
	}
	private: System::Void tableLayoutPanel1_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e) {
	}
	private: System::Void Browse_button_Click(System::Object^ sender, System::EventArgs^ e) {
		OpenFileDialog^ dialog = gcnew OpenFileDialog();
		string filter = "Image Files(*.jpg; *.jpeg; *.gif; *.bmp)|*.jpg; *.jpeg; *.gif; *.bmp";
		String^ str3 = gcnew String(filter.c_str());
		dialog->Filter = str3;
		if (dialog->ShowDialog() == System::Windows::Forms::DialogResult::OK) {
			//MyCamera->Stop();
			pictureBox1->ImageLocation = dialog->FileName;
			pictureBox2->ImageLocation = dialog->FileName;
			changed = true;
		}

	}
	private: System::Void Security_button_Click(System::Object^ sender, System::EventArgs^ e) {
		SecurityGbox->Show();
		AccountGbox->Hide();
		NotificationGbox->Hide();
		Current_Tab_label->Text = "Security";
	}
	private: System::Void Account_button_Click(System::Object^ sender, System::EventArgs^ e) {
		AccountGbox->Show();
		NotificationGbox->Hide();
		SecurityGbox->Hide();
		Current_Tab_label->Text = "Account";


	}
	private: System::Void Notification_button_Click(System::Object^ sender, System::EventArgs^ e) {
		NotificationGbox->Show();
		AccountGbox->Hide();
		SecurityGbox->Hide();
		Current_Tab_label->Text = "Notification";


	}
	private: System::Void No_pic_button_Click(System::Object^ sender, System::EventArgs^ e) {
		pictureBox1->ImageLocation = "PICs\\guest.jpg";
		pictureBox2->ImageLocation = "PICs\\guest.jpg";
		changed = true;

	}
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		save();
		Logoutkey = 'o';
		s_key = '1';
	}
	private: System::Void New_pic_button_Click(System::Object^ sender, System::EventArgs^ e) {
		bool check_errors = false;
		for (int i = 0; i < labels->Count; i++) {
			if (labels[i]->ForeColor == Color::FromArgb(255, 0, 0)) {
				check_errors = true;
				break;
			}
		}
		if (!check_errors) {
			string username;
			MarshalString(Username_Textbox->Text, username);
			string temp = "PICs\\" + username + ".jpg";
			String^ temp_loc = gcnew String(temp.c_str());
			System::IO::File::Delete(temp_loc);
			Camera_winform^ cm = gcnew Camera_winform(username);
			cm->ShowDialog();
			if (who == 'd') {
				string org = "PICs\\Doctors\\" + username + ".jpg";
				String^ org_loc = gcnew String(temp.c_str());
				if (System::IO::File::Exists(temp_loc)) {
					changed = true;
					pictureBox1->ImageLocation = temp_loc;
					pictureBox2->ImageLocation = temp_loc;
				}
				else if (System::IO::File::Exists(org_loc)) {
					pictureBox1->ImageLocation = org_loc;
					pictureBox2->ImageLocation = org_loc;

				}
			}
			else if (who == 'p') {
				string org = "PICs\\Patients\\" + username + ".jpg";
				String^ org_loc = gcnew String(temp.c_str());
				if (System::IO::File::Exists(temp_loc)) {
					changed = true;
					pictureBox1->ImageLocation = temp_loc;
					pictureBox2->ImageLocation = temp_loc;
				}
				else if (System::IO::File::Exists(org_loc)) {
					pictureBox1->ImageLocation = org_loc;
					pictureBox2->ImageLocation = org_loc;

				}
			}
		}
		else {
			System::Windows::Forms::DialogResult Quit_result = MessageBox::Show("You cannot save while having errors,please fix them first", "Errors", MessageBoxButtons::OK, MessageBoxIcon::Exclamation);
		}
	}
	private: System::Void Account_Settings_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
		this->ActiveControl = Name_label;
		bool check_errors = false;
		for (int i = 0; i < labels->Count; i++) {
			if (labels[i]->ForeColor == Color::FromArgb(255, 0, 0)) {
				check_errors = true;
				break;
			}
		}
		string username;
		MarshalString(Username_Textbox->Text, username);
		string temp = "PICs\\" + username + ".jpg";
		String^ temp_loc = gcnew String(temp.c_str());
		if (System::IO::File::Exists(temp_loc))
			System::IO::File::Delete(temp_loc);
		if (!check_errors || Logoutkey == 'b') {
			if (Logoutkey == '0' && s_key == '0' && changed) {
				System::Windows::Forms::DialogResult Quit_result = MessageBox::Show("Do you want to save Current changes?", "Quit?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
				if (Quit_result == System::Windows::Forms::DialogResult::Yes) {
					//Save_button->PerformClick();
					save();
					Logoutkey = 'o';
				}
				else if (Quit_result == System::Windows::Forms::DialogResult::Cancel) {
					e->Cancel = true;
				}
			}
		}
		else {
			System::Windows::Forms::DialogResult Quit_result = MessageBox::Show("You still have errors, do you want to exit without saving?", "Errors", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
			if (Quit_result == System::Windows::Forms::DialogResult::No) {
				//Save_button->PerformClick()
				e->Cancel = true;

			}
		}
	}
	private: System::Void Logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
		bool check_errors = false;
		for (int i = 0; i < labels->Count; i++) {
			if (labels[i]->ForeColor == Color::FromArgb(255, 0, 0)) {
				check_errors = true;
				break;
			}
		}
		if (!check_errors) {
			if (s_key != '1' && changed) {
				System::Windows::Forms::DialogResult Logout_result = MessageBox::Show("Are you sure you want to Logout & save Current changes?", "Logout?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
				if (Logout_result == System::Windows::Forms::DialogResult::Yes) {
					//Save_button->PerformClick();
					save();
					Logoutkey = 'b';
					this->Close();
				}
				else if (Logout_result == System::Windows::Forms::DialogResult::No) {
					Logoutkey = 'n';
					this->Close();
				}
			}
			else {
				System::Windows::Forms::DialogResult Logout_result = MessageBox::Show("Are you sure you want to Logout?", "Logout?", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
				if (Logout_result == System::Windows::Forms::DialogResult::Yes) {
					//Save_button->PerformClick();
					Logoutkey = 'b';
					this->Close();
				}
			}
		}
		else {
			
			System::Windows::Forms::DialogResult Quit_result = MessageBox::Show("You still have errors, do you want to logout without saving?", "Errors", MessageBoxButtons::YesNo, MessageBoxIcon::Exclamation);
			if (Quit_result == System::Windows::Forms::DialogResult::Yes) {
				Logoutkey = 'b';
				this->Close();
			}

		}

	}
	private: System::Void step2_CheckBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		if (step2_CheckBox->Checked == true) {
			step2_phone_label->Show();
			step2_phone_Textbox->Show();
			Send_code_button->Show();
			string randCode;
			srand(time(0));
			randCode = to_string((rand() % 10000000) + 1000000);
			Code = gcnew String(randCode.c_str());
			changed = true;
			Vphone_pictureBox->Show();
			pictureBox4->Show();
			Vphone_pictureBox->SendToBack();


		}
		else {
			step2_phone_label->Hide();
			step2_phone_Textbox->Hide();
			step2_code_label->Hide();
			step2_code_Textbox->Hide();
			Vphone_pictureBox->Hide();
			pictureBox4->Hide();
		}
	}
	private: System::Void step2_phone_Textbox_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
		char ch = e->KeyChar;
		if (!isdigit(ch) && ch != 8)
		{
			e->Handled = true;
		}
	}
	private: System::Void Account_button_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		Account_button->BackColor = Color::FromArgb(255, 255, 255);
		Account_button->ForeColor = Color::FromArgb(0, 0, 0);
	}
	private: System::Void Account_button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Account_button->BackColor = Color::FromArgb(0, 102, 204);
		Account_button->ForeColor = Color::FromArgb(255, 255, 255);
	}
	private: System::Void Security_button_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		Security_button->BackColor = Color::FromArgb(255, 255, 255);
		Security_button->ForeColor = Color::FromArgb(0, 0, 0);
	}
	private: System::Void Security_button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Security_button->BackColor = Color::FromArgb(0, 102, 204);
		Security_button->ForeColor = Color::FromArgb(255, 255, 255);
	}
	private: System::Void Notification_button_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		Notification_button->BackColor = Color::FromArgb(255, 255, 255);
		Notification_button->ForeColor = Color::FromArgb(0, 0, 0);
	}
	private: System::Void Notification_button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Notification_button->BackColor = Color::FromArgb(0, 102, 204);
		Notification_button->ForeColor = Color::FromArgb(255, 255, 255);
	}
	private: System::Void Save_button_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		Save_button->BackColor = Color::FromArgb(255, 255, 255);
		Save_button->ForeColor = Color::FromArgb(0, 0, 0);
	}
	private: System::Void Save_button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Save_button->BackColor = Color::FromArgb(0, 102, 204);
		Save_button->ForeColor = Color::FromArgb(255, 255, 255);
	}
	private: System::Void Logout_button_MouseHover(System::Object^ sender, System::EventArgs^ e) {
		Logout_button->BackColor = Color::FromArgb(255, 255, 255);
		Logout_button->ForeColor = Color::FromArgb(0, 0, 0);
	}
	private: System::Void Logout_button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
		Logout_button->BackColor = Color::FromArgb(0, 102, 204);
		Logout_button->ForeColor = Color::FromArgb(255, 255, 255);
	}
	private: System::Void Send_code_button_Click(System::Object^ sender, System::EventArgs^ e) {

		System::Windows::Forms::DialogResult Logout_result = MessageBox::Show("A message has been sent to this phone number", "Send code!", MessageBoxButtons::OK, MessageBoxIcon::Warning);
		step2_code_label->Show();
		step2_code_Textbox->Show();
		VCODE_pictureBox->Show();
		pictureBox5->Show();
		VCODE_pictureBox->SendToBack();
	}
	private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Fullname_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Bluen(Name_picturebox, Name_label);
	}
	private: System::Void Username_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Bluen(Username_picturebox, Username);
	}
	private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {

	}
	private: System::Void Username_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		changed = true;
		string UNAME;
		MarshalString(Username_Textbox->Text, UNAME);
	}
	private: System::Void Phone_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Bluen(Phone_picturebox, Phone);
	}
	private: System::Void Fullname_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		changed = true;
	}
	private: System::Void Phone_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		changed = true;

	}
	private: System::Void Password_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		timer1_counter2 = 0;
		changed = true;
		if (label9->ForeColor == Color::FromArgb(0, 102, 204)) {
			Password_label_error->Text = "";
			string old_p;
			MarshalString(old_pass, old_p);
			string new_p;
			MarshalString(Password_Textbox->Text, new_p);
			string curr_uname;
			MarshalString(Username_Textbox->Text, curr_uname);	
			if (old_p != new_p) {
				string org2 = "";
				for (int i = 0; i < curr_uname.size(); i++) {
					org2 += char(tolower(curr_uname[i]));
				}
				string org1 = "";
				for (int i = 0; i < new_p.size(); i++) {
					org1 += char(tolower(new_p[i]));
				}
				if (org1 != org2) {
					timer1->Start();
					Password_label_error->Hide();
					Green(Password_pictureBox, label9);
					textBox1->Focus();

				}
				else {
					Password_label_error->Text = "Password cannot be the same as Username";
					Password_label_error->Show();
					Red(Password_pictureBox, label9);
				}
			}
		}
		
	}
	private: System::Void step2_phone_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		changed = true;

	}
	private: System::Void step2_code_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		changed = true;

	}
	private: System::Void Email_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		changed = true;

	}
	private: System::Void Email_checkBox_CheckedChanged(System::Object^ sender, System::EventArgs^ e) {
		changed = true;
	}
	private: System::Void Username_Textbox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
		string new_uname;
		MarshalString(Username_Textbox->Text, new_uname);
		string old_uname;
		MarshalString(old_username, old_uname);
		bool test_name = false;
		Username_error_label->Text = "";

		if (new_uname != old_uname) {
			if (new_uname.size() >= 3) {
				for (int i = 0; i < new_uname.size(); i++) {
					char c = new_uname[i];
					if (!isalnum(c)) {
					
						/*label2->Text = "username cannot have symbols";
						label2->Show();*/
						Username_error_label->Text+= "Username cannot have symbols\n";
						Username_error_label->Show();
						test_name = false;
						Red(Username_picturebox, Username);
						e->Cancel = true;
						break;
					}
					test_name = true;
					Blacken(Username_picturebox, Username);
					e->Cancel = false;
				}
				
			}
			else {
				Username_error_label->Text += "Username should be 3 characters or more\n";
				Username_error_label->Show();
				Red(Username_picturebox, Username);
				e->Cancel = true;
			}
			if (test_name) {
				for (int i = 0; i < UNAMES->Count; i++) {
					string u;
					MarshalString(UNAMES[i], u);
					string org2 = "";
					for (int j = 0; j < u.size(); j++) {
						if (isalpha(u[j]))
							org2 += char(tolower(u[j]));
						else {
							org2 += u[j];
						}
					}
					string org = "";
					for (int j = 0; j < new_uname.size(); j++) {
						if (isalpha(new_uname[j]))
							org += char(tolower(new_uname[j]));
						else {
							org += new_uname[j];
						}
					}

					if (org==org2) {
						Username_error_label->Text = "This Username is already taken\n";
						Username_error_label->Show();

						Red(Username_picturebox, Username);
						e->Cancel = true;
					}
					else {
						Green(Username_picturebox, Username);
						Username_error_label->Hide();
						e->Cancel = false;
					}

				}

			}
		}
		else {
			Blacken(Username_picturebox, Username);
		}
	}
	private: System::Void AccountGbox_Enter(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Name_pictureBox2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Password_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Bluen(Password_pictureBox, label9);
	}
	private: System::Void step2_phone_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Bluen(Vphone_pictureBox, step2_phone_label);
	}
	private: System::Void Email_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		Bluen(Email_picturebox, label10);
	}
	private: System::Void step2_code_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	}
private: System::Void Fullname_Textbox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	string old_fullname;
	MarshalString(old_name, old_fullname);
	string new_fullname;
	MarshalString(Fullname_Textbox->Text, new_fullname);
	bool check_name = false;
	if (old_fullname != new_fullname) {
		if (new_fullname.size() >= 3) {
			for (int i = 0; i < new_fullname.size(); i++) {
				if (!isalnum(new_fullname[i])) {
					check_name = true;
					break;
				}

			}
			Fullname_error_label->Hide();
			Blacken(Name_picturebox, Name_label);
			e->Cancel = false;
		}
		else {
			Fullname_error_label->Text = "Full Name should be more than three characters";
			Fullname_error_label->Show();
			Red(Name_picturebox, Name_label);
			e->Cancel = true;  
		}
	}
	if (check_name) {
		Fullname_error_label->Text = "Full Name should not contain special characters";
		Red(Name_picturebox, Name_label);
		e->Cancel = true;
	}

}
private: System::Void Phone_Textbox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	string old_p;
	MarshalString(old_phone, old_p);
	string new_p;
	MarshalString(Phone_Textbox->Text, new_p);
	double mphone = System::Convert::ToDouble(Phone_Textbox->Text);
	double cphone = mphone;
	bool vphone = true;
	int lengthCount = 1;
	if (old_p != new_p) {
		for (; cphone > 0.9; cphone /= 10, lengthCount++);//Here we count the entered numbers
		if (lengthCount != 11) {
			vphone = false;
			Phone_error_label->Text = "Phone numbers are 11 numbers";
			Phone_error_label->Show();

		}
		int check[11];
		for (int i = lengthCount - 1; i >= 0; i--) {
			check[i] = (int)mphone % 10;
			mphone /= 10;
		}
		if (check[2] != 1 && check[2] != 2 && check[2] != 0 && check[2] != 5) {
			Phone_error_label->Text = "Invalid phone number";
			Phone_error_label->Show();
			vphone = false;
		}
		if (vphone) {
			Blacken(Phone_picturebox, Phone);
			e->Cancel = false;
			for (int i = 0; i < PHONES->Count; i++) {
				if (Phone_Textbox->Text == PHONES[i]) {
					Red(Phone_picturebox, Phone);
					e->Cancel = true;
					Phone_error_label->Text = "This phone number is already taken\n";
					Phone_error_label->Show();
				}
			}
		}
		else {
			Red(Phone_picturebox, Phone);
			e->Cancel = true;
		}
	}
}
private: System::Void Password_Textbox_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	if (label9->ForeColor == Color::Red) {
		e->Cancel = true;
	}
	else 
		e->Cancel = false;
}
private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (timer1_counter2 == 120) {
		if (curr_loc != Password_Textbox->Location.Y + 70) {
			if (timer1_counter == 70) {
				timer1_counter = 0;
				timer1->Stop();
			}
			timer1_counter += 10;
			Password_Textbox->Location = Drawing::Point(Password_Textbox->Location.X, Password_Textbox->Location.Y - 10);
			Password_label_error->Location = Drawing::Point(Password_label_error->Location.X, Password_label_error->Location.Y - 10);
			Password_pictureBox->Location = Drawing::Point(Password_pictureBox->Location.X, Password_pictureBox->Location.Y - 10);
			pictureBox3->Location = Drawing::Point(pictureBox3->Location.X, pictureBox3->Location.Y - 10);
			label9->Location = Drawing::Point(label9->Location.X, label9->Location.Y - 10);
			Reenter->Show();
			pictureBox7->Show();
			pictureBox8->Show();
			textBox1->Show();
			Blacken(pictureBox8, Reenter);
			textBox1->Focus();
		}
	}
	else
		timer1_counter2 += 5;	
	
}
private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	if (timer2_counter2 == 120) {
		if (timer2_counter == 70) {
		timer2_counter2 = 0;
			timer2_counter = 0;		
			timer2->Stop();
			Reenter->Hide();
			pictureBox7->Hide();
			pictureBox8->Hide();
			textBox1->Hide();
			textBox1->Text = "";
		}
		timer2_counter += 10;
		Password_Textbox->Location = Drawing::Point(Password_Textbox->Location.X, Password_Textbox->Location.Y + 10);
		Password_label_error->Location = Drawing::Point(Password_label_error->Location.X, Password_label_error->Location.Y + 10);
		Password_pictureBox->Location = Drawing::Point(Password_pictureBox->Location.X, Password_pictureBox->Location.Y + 10);
		pictureBox3->Location = Drawing::Point(pictureBox3->Location.X, pictureBox3->Location.Y + 10);
		label9->Location = Drawing::Point(label9->Location.X, label9->Location.Y + 10);


	}
	else
	timer2_counter2 += 5;
}
private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	
}
private: System::Void timer3_Tick(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void textBox1_Validating(System::Object^ sender, System::ComponentModel::CancelEventArgs^ e) {
	if (textBox1->Text == Password_Textbox->Text) {
		timer2->Start();
		Green(pictureBox8, Reenter);
		Reenter_error_label->Hide();
		this->ActiveControl = label9;
		e->Cancel = false;
	}
	else {
		if (Reenter->ForeColor != Color::FromArgb(0, 255, 0)) {
			Reenter_error_label->Text = "Passwords do not match";
			Reenter_error_label->Show();
			Red(pictureBox8, Reenter);
			e->Cancel = true;
		}
		else {
			Blacken(pictureBox8, Reenter);
		}

	}
}
};
}
