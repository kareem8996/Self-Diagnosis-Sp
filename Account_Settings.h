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
	/// <summary>
	/// Summary for Account_Settings
	/// </summary>
	public ref class Account_Settings : public System::Windows::Forms::Form
	{
		// your secondary/popup form's class
		
	public: delegate void WipeMouthEventHandler(bool LeftOrRightHand);

	 WipeMouthEventHandler^ ev = gcnew WipeMouthEventHandler(funcC);


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

		static String^ Code;
		
		char who = 's';
	private: System::Windows::Forms::PictureBox^ Name_picturebox;
	private: System::Windows::Forms::PictureBox^ Name_pictureBox2;
	private: System::Windows::Forms::PictureBox^ Username_picturebox2;
	private: System::Windows::Forms::PictureBox^ Username_picturebox;
	private: System::Windows::Forms::PictureBox^ Phone_picturebox2;
	private: System::Windows::Forms::PictureBox^ Phone_picturebox;





	public:

	public:
		
		bool ufunC(function<bool(string)>func,string username) {
			return func(username);
		}
		bool changed = false;
		char s_key = '0';

		void Blue(PictureBox^p,Label^l) {
			l ->ForeColor = Color::FromArgb(0, 102, 204);
			p->BackColor = Color::FromArgb(0, 102, 204);
		}
		void Red(PictureBox^p,Label^l) {
			l ->ForeColor = Color::FromArgb(255,0,0);
			p->BackColor = Color::FromArgb(255,0,0);
		}
		void Blacken(PictureBox^p,Label^l) {
			l ->ForeColor = Color::FromArgb(0,0,0);
			p->BackColor = Color::FromArgb(0,0,0);
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
		Account_Settings(string Fullname, string username, string pass, string email, string phone,char send_email, function<bool(string)> ufunc, function<bool(string)> efunc, function<bool(string)> pfunc)
		{
			InitializeComponent();
			
			who = 'd';
			String^ name = gcnew String(Fullname.c_str());
			String^ uname = gcnew String(username.c_str());
			String^ p = gcnew String(pass.c_str());
			String^ Em = gcnew String(email.c_str());
			String^ pho = gcnew String(phone.c_str());
			Fullname_Textbox->Text = name;
			Hello_label->Text ="Hello Dr. " + name;
			Username_Textbox->Text = uname;
			Email_Textbox->Text = Em;
			Phone_Textbox->Text = pho;
			step2_phone_Textbox->Text = pho;
			Password_Textbox->Text = p;
			if (send_email=='T') {
				Email_checkBox->Checked=true;
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
			//panel3->Show();
			//Password_Textbox->Text = p;
			//
			//TODO: Add the constructor code here
			//
		}
		Account_Settings(string Fullname, string username, string pass, string email,char gender, function<void(string)> ufunc, function<void(string)> efunc, function<void(string)> pfunc)
		{
			InitializeComponent();
			who = 'p';
			String^ name = gcnew String(Fullname.c_str());
			String^ uname = gcnew String(username.c_str());
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

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Account_Settings::typeid));
			this->Fullname_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->Username_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->Phone_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->AccountGbox = (gcnew System::Windows::Forms::GroupBox());
			this->Phone = (gcnew System::Windows::Forms::Label());
			this->Phone_picturebox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Phone_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->Username = (gcnew System::Windows::Forms::Label());
			this->Username_picturebox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Username_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Browse_button = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->Name_label = (gcnew System::Windows::Forms::Label());
			this->New_pic_button = (gcnew System::Windows::Forms::Button());
			this->No_pic_button = (gcnew System::Windows::Forms::Button());
			this->Name_pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->Name_picturebox = (gcnew System::Windows::Forms::PictureBox());
			this->NotificationGbox = (gcnew System::Windows::Forms::GroupBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->Email_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->Email_checkBox = (gcnew System::Windows::Forms::CheckBox());
			this->SecurityGbox = (gcnew System::Windows::Forms::GroupBox());
			this->Send_code_button = (gcnew System::Windows::Forms::Button());
			this->step2_code_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->step2_code_label = (gcnew System::Windows::Forms::Label());
			this->step2_phone_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->step2_phone_label = (gcnew System::Windows::Forms::Label());
			this->step2_CheckBox = (gcnew System::Windows::Forms::CheckBox());
			this->Password_Textbox = (gcnew System::Windows::Forms::TextBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
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
			this->AccountGbox->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_pictureBox2))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_picturebox))->BeginInit();
			this->NotificationGbox->SuspendLayout();
			this->SecurityGbox->SuspendLayout();
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
			// 
			// Username_Textbox
			// 
			this->Username_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Username_Textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Username_Textbox->Location = System::Drawing::Point(33, 265);
			this->Username_Textbox->Name = L"Username_Textbox";
			this->Username_Textbox->Size = System::Drawing::Size(325, 27);
			this->Username_Textbox->TabIndex = 1;
			this->Username_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::Username_Textbox_MouseClick);
			this->Username_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Username_Textbox_TextChanged);
			// 
			// Phone_Textbox
			// 
			this->Phone_Textbox->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->Phone_Textbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Phone_Textbox->Location = System::Drawing::Point(32, 357);
			this->Phone_Textbox->Name = L"Phone_Textbox";
			this->Phone_Textbox->Size = System::Drawing::Size(324, 27);
			this->Phone_Textbox->TabIndex = 3;
			this->Phone_Textbox->MouseClick += gcnew System::Windows::Forms::MouseEventHandler(this, &Account_Settings::Phone_Textbox_MouseClick);
			this->Phone_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Phone_Textbox_TextChanged);
			this->Phone_Textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account_Settings::Phone_Textbox_KeyPress);
			// 
			// AccountGbox
			// 
			this->AccountGbox->BackColor = System::Drawing::Color::White;
			this->AccountGbox->Controls->Add(this->Phone);
			this->AccountGbox->Controls->Add(this->Phone_Textbox);
			this->AccountGbox->Controls->Add(this->Phone_picturebox2);
			this->AccountGbox->Controls->Add(this->Phone_picturebox);
			this->AccountGbox->Controls->Add(this->Username_Textbox);
			this->AccountGbox->Controls->Add(this->Username);
			this->AccountGbox->Controls->Add(this->Username_picturebox2);
			this->AccountGbox->Controls->Add(this->Username_picturebox);
			this->AccountGbox->Controls->Add(this->pictureBox1);
			this->AccountGbox->Controls->Add(this->Browse_button);
			this->AccountGbox->Controls->Add(this->label5);
			this->AccountGbox->Controls->Add(this->Name_label);
			this->AccountGbox->Controls->Add(this->Fullname_Textbox);
			this->AccountGbox->Controls->Add(this->New_pic_button);
			this->AccountGbox->Controls->Add(this->No_pic_button);
			this->AccountGbox->Controls->Add(this->Name_pictureBox2);
			this->AccountGbox->Controls->Add(this->Name_picturebox);
			this->AccountGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AccountGbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AccountGbox->Location = System::Drawing::Point(286, 0);
			this->AccountGbox->Name = L"AccountGbox";
			this->AccountGbox->Size = System::Drawing::Size(825, 745);
			this->AccountGbox->TabIndex = 4;
			this->AccountGbox->TabStop = false;
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
			this->Phone_picturebox2->Location = System::Drawing::Point(30, 350);
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
			this->Username->Location = System::Drawing::Point(58, 232);
			this->Username->Name = L"Username";
			this->Username->Size = System::Drawing::Size(117, 30);
			this->Username->TabIndex = 5;
			this->Username->Text = L"Username:";
			// 
			// Username_picturebox2
			// 
			this->Username_picturebox2->Location = System::Drawing::Point(33, 259);
			this->Username_picturebox2->Name = L"Username_picturebox2";
			this->Username_picturebox2->Size = System::Drawing::Size(328, 45);
			this->Username_picturebox2->TabIndex = 16;
			this->Username_picturebox2->TabStop = false;
			// 
			// Username_picturebox
			// 
			this->Username_picturebox->BackColor = System::Drawing::Color::Black;
			this->Username_picturebox->Location = System::Drawing::Point(30, 255);
			this->Username_picturebox->Name = L"Username_picturebox";
			this->Username_picturebox->Size = System::Drawing::Size(333, 53);
			this->Username_picturebox->TabIndex = 15;
			this->Username_picturebox->TabStop = false;
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
			// NotificationGbox
			// 
			this->NotificationGbox->BackColor = System::Drawing::Color::White;
			this->NotificationGbox->Controls->Add(this->label11);
			this->NotificationGbox->Controls->Add(this->Email_Textbox);
			this->NotificationGbox->Controls->Add(this->label10);
			this->NotificationGbox->Controls->Add(this->Email_checkBox);
			this->NotificationGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NotificationGbox->Location = System::Drawing::Point(286, 0);
			this->NotificationGbox->Name = L"NotificationGbox";
			this->NotificationGbox->Size = System::Drawing::Size(781, 739);
			this->NotificationGbox->TabIndex = 7;
			this->NotificationGbox->TabStop = false;
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
			// Email_Textbox
			// 
			this->Email_Textbox->Location = System::Drawing::Point(288, 273);
			this->Email_Textbox->Name = L"Email_Textbox";
			this->Email_Textbox->Size = System::Drawing::Size(305, 24);
			this->Email_Textbox->TabIndex = 7;
			this->Email_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Email_Textbox_TextChanged);
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(46, 259);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 36);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Email";
			// 
			// Email_checkBox
			// 
			this->Email_checkBox->AutoSize = true;
			this->Email_checkBox->Location = System::Drawing::Point(503, 344);
			this->Email_checkBox->Name = L"Email_checkBox";
			this->Email_checkBox->Size = System::Drawing::Size(18, 17);
			this->Email_checkBox->TabIndex = 9;
			this->Email_checkBox->UseVisualStyleBackColor = true;
			this->Email_checkBox->CheckedChanged += gcnew System::EventHandler(this, &Account_Settings::Email_checkBox_CheckedChanged);
			// 
			// SecurityGbox
			// 
			this->SecurityGbox->BackColor = System::Drawing::Color::White;
			this->SecurityGbox->Controls->Add(this->Send_code_button);
			this->SecurityGbox->Controls->Add(this->step2_code_Textbox);
			this->SecurityGbox->Controls->Add(this->step2_code_label);
			this->SecurityGbox->Controls->Add(this->step2_phone_Textbox);
			this->SecurityGbox->Controls->Add(this->step2_phone_label);
			this->SecurityGbox->Controls->Add(this->step2_CheckBox);
			this->SecurityGbox->Controls->Add(this->Password_Textbox);
			this->SecurityGbox->Controls->Add(this->label8);
			this->SecurityGbox->Controls->Add(this->label9);
			this->SecurityGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->SecurityGbox->Location = System::Drawing::Point(286, 0);
			this->SecurityGbox->Name = L"SecurityGbox";
			this->SecurityGbox->Size = System::Drawing::Size(770, 822);
			this->SecurityGbox->TabIndex = 8;
			this->SecurityGbox->TabStop = false;
			// 
			// Send_code_button
			// 
			this->Send_code_button->Location = System::Drawing::Point(657, 370);
			this->Send_code_button->Name = L"Send_code_button";
			this->Send_code_button->Size = System::Drawing::Size(66, 23);
			this->Send_code_button->TabIndex = 16;
			this->Send_code_button->Text = L"Send";
			this->Send_code_button->UseVisualStyleBackColor = true;
			this->Send_code_button->Click += gcnew System::EventHandler(this, &Account_Settings::Send_code_button_Click);
			// 
			// step2_code_Textbox
			// 
			this->step2_code_Textbox->Location = System::Drawing::Point(288, 444);
			this->step2_code_Textbox->Name = L"step2_code_Textbox";
			this->step2_code_Textbox->Size = System::Drawing::Size(305, 24);
			this->step2_code_Textbox->TabIndex = 15;
			this->step2_code_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::step2_code_Textbox_TextChanged);
			// 
			// step2_code_label
			// 
			this->step2_code_label->AutoSize = true;
			this->step2_code_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->step2_code_label->Location = System::Drawing::Point(33, 427);
			this->step2_code_label->Name = L"step2_code_label";
			this->step2_code_label->Size = System::Drawing::Size(247, 41);
			this->step2_code_label->TabIndex = 14;
			this->step2_code_label->Text = L"Verification code";
			// 
			// step2_phone_Textbox
			// 
			this->step2_phone_Textbox->Location = System::Drawing::Point(288, 369);
			this->step2_phone_Textbox->Name = L"step2_phone_Textbox";
			this->step2_phone_Textbox->Size = System::Drawing::Size(305, 24);
			this->step2_phone_Textbox->TabIndex = 13;
			this->step2_phone_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::step2_phone_Textbox_TextChanged);
			this->step2_phone_Textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account_Settings::step2_phone_Textbox_KeyPress);
			// 
			// step2_phone_label
			// 
			this->step2_phone_label->AutoSize = true;
			this->step2_phone_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->step2_phone_label->Location = System::Drawing::Point(25, 352);
			this->step2_phone_label->Name = L"step2_phone_label";
			this->step2_phone_label->Size = System::Drawing::Size(113, 41);
			this->step2_phone_label->TabIndex = 12;
			this->step2_phone_label->Text = L" Phone";
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
			// Password_Textbox
			// 
			this->Password_Textbox->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Password_Textbox->Location = System::Drawing::Point(288, 236);
			this->Password_Textbox->Name = L"Password_Textbox";
			this->Password_Textbox->Size = System::Drawing::Size(305, 26);
			this->Password_Textbox->TabIndex = 8;
			this->Password_Textbox->TextChanged += gcnew System::EventHandler(this, &Account_Settings::Password_Textbox_TextChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label8->Location = System::Drawing::Point(25, 278);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(322, 41);
			this->label8->TabIndex = 6;
			this->label8->Text = L" For 2 step verification";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label9->Location = System::Drawing::Point(25, 218);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(155, 41);
			this->label9->TabIndex = 4;
			this->label9->Text = L" Password";
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
			// Account_Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ClientSize = System::Drawing::Size(1054, 715);
			this->Controls->Add(this->Current_Tab_label);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->AccountGbox);
			this->Controls->Add(this->SecurityGbox);
			this->Controls->Add(this->NotificationGbox);
			this->Name = L"Account_Settings";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Account_Settings";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Account_Settings::Account_Settings_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Account_Settings::Account_Settings_Load);
			this->AccountGbox->ResumeLayout(false);
			this->AccountGbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Phone_picturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Username_picturebox))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_pictureBox2))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Name_picturebox))->EndInit();
			this->NotificationGbox->ResumeLayout(false);
			this->NotificationGbox->PerformLayout();
			this->SecurityGbox->ResumeLayout(false);
			this->SecurityGbox->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel1->ResumeLayout(false);
			this->tableLayoutPanel1->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Account_Settings_Load(System::Object^ sender, System::EventArgs^ e) {
		Show_Account();
		changed = false;
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
	s_key ='1';
}
private: System::Void New_pic_button_Click(System::Object^ sender, System::EventArgs^ e) {
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
private: System::Void Account_Settings_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	string username;
	MarshalString(Username_Textbox->Text, username);
	string temp = "PICs\\" + username + ".jpg";
	String^ temp_loc = gcnew String(temp.c_str());
	if (System::IO::File::Exists(temp_loc))
		System::IO::File::Delete(temp_loc);
	if(Logoutkey=='0'&&s_key=='0'&&changed) {
		System::Windows::Forms::DialogResult Quit_result = MessageBox::Show("Do you want to save Current changes?", "Quit?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
		if (Quit_result== System::Windows::Forms::DialogResult::Yes) {
			//Save_button->PerformClick();
			save();
			Logoutkey = 'o';
		}
		else if(Quit_result == System::Windows::Forms::DialogResult::Cancel) {
			e->Cancel = true;
		}
	}

}
private: System::Void Logout_button_Click(System::Object^ sender, System::EventArgs^ e) {
	if (s_key != '1'&&changed) {
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
		System::Windows::Forms::DialogResult Logout_result = MessageBox::Show("Are you sure you want to Logout ?", "Logout?", MessageBoxButtons::YesNo, MessageBoxIcon::Question);
		if (Logout_result == System::Windows::Forms::DialogResult::Yes) {
			//Save_button->PerformClick();
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

		
	}
	else { 
		step2_phone_label->Hide();
		step2_phone_Textbox->Hide();
		step2_code_label->Hide();
		step2_code_Textbox->Hide();
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
	Account_button->ForeColor = Color::FromArgb(0,0,0);
}
private: System::Void Account_button_MouseLeave(System::Object^ sender, System::EventArgs^ e) {
	Account_button->BackColor = Color::FromArgb(0, 102, 204);
	Account_button->ForeColor = Color::FromArgb(255,255,255);
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
}
private: System::Void pictureBox3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void Fullname_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Blue(Name_picturebox, Name_label);
	Blacken(Phone_picturebox, Phone);
	Blacken(Username_picturebox, Username);
}
private: System::Void Username_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Blacken(Name_picturebox, Name_label);
	Blacken(Phone_picturebox, Phone);
	Blue(Username_picturebox, Username);
}
private: System::Void label4_Click(System::Object^ sender, System::EventArgs^ e) {

}
private: System::Void Username_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	changed = true;
	string username;
	MarshalString(Fullname_Textbox->Text, username);

}
private: System::Void Phone_Textbox_MouseClick(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	Blacken(Name_picturebox, Name_label);
	Blue(Phone_picturebox, Phone);
	Blacken(Username_picturebox, Username);
}
private: System::Void Fullname_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	changed = true;
}
private: System::Void Phone_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	changed = true;

}
private: System::Void Password_Textbox_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	changed = true;

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
};
}
