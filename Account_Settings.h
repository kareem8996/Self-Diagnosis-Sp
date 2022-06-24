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

	private: System::Windows::Forms::TextBox^ Fullname_Textbox;
	private: System::Windows::Forms::TextBox^ Username_Textbox;

	private: System::Windows::Forms::GroupBox^ AccountGbox;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label4;

	private: System::Windows::Forms::Label^ label2;
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
		Account_Settings(string Fullname, string username, string pass, string email, string phone,char send_email)
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
		Account_Settings(string Fullname, string username, string pass, string email,char gender)
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
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Browse_button = (gcnew System::Windows::Forms::Button());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->New_pic_button = (gcnew System::Windows::Forms::Button());
			this->No_pic_button = (gcnew System::Windows::Forms::Button());
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
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
			this->Fullname_Textbox->Location = System::Drawing::Point(245, 182);
			this->Fullname_Textbox->Name = L"Fullname_Textbox";
			this->Fullname_Textbox->Size = System::Drawing::Size(348, 25);
			this->Fullname_Textbox->TabIndex = 0;
			// 
			// Username_Textbox
			// 
			this->Username_Textbox->Location = System::Drawing::Point(245, 269);
			this->Username_Textbox->Name = L"Username_Textbox";
			this->Username_Textbox->Size = System::Drawing::Size(348, 25);
			this->Username_Textbox->TabIndex = 1;
			// 
			// Phone_Textbox
			// 
			this->Phone_Textbox->Location = System::Drawing::Point(245, 349);
			this->Phone_Textbox->Name = L"Phone_Textbox";
			this->Phone_Textbox->Size = System::Drawing::Size(348, 25);
			this->Phone_Textbox->TabIndex = 3;
			this->Phone_Textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account_Settings::Phone_Textbox_KeyPress);
			// 
			// AccountGbox
			// 
			this->AccountGbox->BackColor = System::Drawing::Color::White;
			this->AccountGbox->Controls->Add(this->pictureBox1);
			this->AccountGbox->Controls->Add(this->Browse_button);
			this->AccountGbox->Controls->Add(this->label5);
			this->AccountGbox->Controls->Add(this->label4);
			this->AccountGbox->Controls->Add(this->label2);
			this->AccountGbox->Controls->Add(this->label1);
			this->AccountGbox->Controls->Add(this->Phone_Textbox);
			this->AccountGbox->Controls->Add(this->Username_Textbox);
			this->AccountGbox->Controls->Add(this->Fullname_Textbox);
			this->AccountGbox->Controls->Add(this->New_pic_button);
			this->AccountGbox->Controls->Add(this->No_pic_button);
			this->AccountGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->AccountGbox->Font = (gcnew System::Drawing::Font(L"Segoe UI", 7.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->AccountGbox->Location = System::Drawing::Point(327, 0);
			this->AccountGbox->Name = L"AccountGbox";
			this->AccountGbox->Size = System::Drawing::Size(943, 745);
			this->AccountGbox->TabIndex = 4;
			this->AccountGbox->TabStop = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(312, 420);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(159, 155);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 9;
			this->pictureBox1->TabStop = false;
			// 
			// Browse_button
			// 
			this->Browse_button->Location = System::Drawing::Point(528, 442);
			this->Browse_button->Name = L"Browse_button";
			this->Browse_button->Size = System::Drawing::Size(104, 39);
			this->Browse_button->TabIndex = 10;
			this->Browse_button->Text = L" Browse";
			this->Browse_button->UseVisualStyleBackColor = true;
			this->Browse_button->Click += gcnew System::EventHandler(this, &Account_Settings::Browse_button_Click);
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label5->Location = System::Drawing::Point(50, 484);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(219, 41);
			this->label5->TabIndex = 8;
			this->label5->Text = L" Profile picture";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label4->Location = System::Drawing::Point(50, 333);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(113, 41);
			this->label4->TabIndex = 7;
			this->label4->Text = L" Phone";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label2->Location = System::Drawing::Point(50, 253);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(164, 41);
			this->label2->TabIndex = 5;
			this->label2->Text = L" Username";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label1->Location = System::Drawing::Point(50, 166);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(108, 41);
			this->label1->TabIndex = 4;
			this->label1->Text = L" Name";
			// 
			// New_pic_button
			// 
			this->New_pic_button->Location = System::Drawing::Point(661, 471);
			this->New_pic_button->Name = L"New_pic_button";
			this->New_pic_button->Size = System::Drawing::Size(104, 54);
			this->New_pic_button->TabIndex = 12;
			this->New_pic_button->Text = L" Take a New Picture";
			this->New_pic_button->UseVisualStyleBackColor = true;
			this->New_pic_button->Click += gcnew System::EventHandler(this, &Account_Settings::New_pic_button_Click);
			// 
			// No_pic_button
			// 
			this->No_pic_button->Location = System::Drawing::Point(528, 502);
			this->No_pic_button->Name = L"No_pic_button";
			this->No_pic_button->Size = System::Drawing::Size(104, 48);
			this->No_pic_button->TabIndex = 11;
			this->No_pic_button->Text = L" No Profile picture";
			this->No_pic_button->UseVisualStyleBackColor = true;
			this->No_pic_button->Click += gcnew System::EventHandler(this, &Account_Settings::No_pic_button_Click);
			// 
			// NotificationGbox
			// 
			this->NotificationGbox->BackColor = System::Drawing::Color::White;
			this->NotificationGbox->Controls->Add(this->label11);
			this->NotificationGbox->Controls->Add(this->Email_Textbox);
			this->NotificationGbox->Controls->Add(this->label10);
			this->NotificationGbox->Controls->Add(this->Email_checkBox);
			this->NotificationGbox->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->NotificationGbox->Location = System::Drawing::Point(327, 0);
			this->NotificationGbox->Name = L"NotificationGbox";
			this->NotificationGbox->Size = System::Drawing::Size(893, 739);
			this->NotificationGbox->TabIndex = 7;
			this->NotificationGbox->TabStop = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label11->Location = System::Drawing::Point(52, 336);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(399, 25);
			this->label11->TabIndex = 8;
			this->label11->Text = L"Receive an email for each patient diagnosed ";
			// 
			// Email_Textbox
			// 
			this->Email_Textbox->Location = System::Drawing::Point(329, 273);
			this->Email_Textbox->Name = L"Email_Textbox";
			this->Email_Textbox->Size = System::Drawing::Size(348, 22);
			this->Email_Textbox->TabIndex = 7;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 18, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label10->Location = System::Drawing::Point(52, 259);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(88, 36);
			this->label10->TabIndex = 6;
			this->label10->Text = L"Email";
			// 
			// Email_checkBox
			// 
			this->Email_checkBox->AutoSize = true;
			this->Email_checkBox->Location = System::Drawing::Point(575, 344);
			this->Email_checkBox->Name = L"Email_checkBox";
			this->Email_checkBox->Size = System::Drawing::Size(18, 17);
			this->Email_checkBox->TabIndex = 9;
			this->Email_checkBox->UseVisualStyleBackColor = true;
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
			this->SecurityGbox->Location = System::Drawing::Point(327, 0);
			this->SecurityGbox->Name = L"SecurityGbox";
			this->SecurityGbox->Size = System::Drawing::Size(880, 822);
			this->SecurityGbox->TabIndex = 8;
			this->SecurityGbox->TabStop = false;
			// 
			// Send_code_button
			// 
			this->Send_code_button->Location = System::Drawing::Point(751, 370);
			this->Send_code_button->Name = L"Send_code_button";
			this->Send_code_button->Size = System::Drawing::Size(75, 23);
			this->Send_code_button->TabIndex = 16;
			this->Send_code_button->Text = L"Send";
			this->Send_code_button->UseVisualStyleBackColor = true;
			this->Send_code_button->Click += gcnew System::EventHandler(this, &Account_Settings::Send_code_button_Click);
			// 
			// step2_code_Textbox
			// 
			this->step2_code_Textbox->Location = System::Drawing::Point(329, 444);
			this->step2_code_Textbox->Name = L"step2_code_Textbox";
			this->step2_code_Textbox->Size = System::Drawing::Size(348, 22);
			this->step2_code_Textbox->TabIndex = 15;
			// 
			// step2_code_label
			// 
			this->step2_code_label->AutoSize = true;
			this->step2_code_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->step2_code_label->Location = System::Drawing::Point(38, 427);
			this->step2_code_label->Name = L"step2_code_label";
			this->step2_code_label->Size = System::Drawing::Size(247, 41);
			this->step2_code_label->TabIndex = 14;
			this->step2_code_label->Text = L"Verification code";
			// 
			// step2_phone_Textbox
			// 
			this->step2_phone_Textbox->Location = System::Drawing::Point(329, 369);
			this->step2_phone_Textbox->Name = L"step2_phone_Textbox";
			this->step2_phone_Textbox->Size = System::Drawing::Size(348, 22);
			this->step2_phone_Textbox->TabIndex = 13;
			this->step2_phone_Textbox->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &Account_Settings::step2_phone_Textbox_KeyPress);
			// 
			// step2_phone_label
			// 
			this->step2_phone_label->AutoSize = true;
			this->step2_phone_label->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->step2_phone_label->Location = System::Drawing::Point(29, 352);
			this->step2_phone_label->Name = L"step2_phone_label";
			this->step2_phone_label->Size = System::Drawing::Size(113, 41);
			this->step2_phone_label->TabIndex = 12;
			this->step2_phone_label->Text = L" Phone";
			// 
			// step2_CheckBox
			// 
			this->step2_CheckBox->AutoSize = true;
			this->step2_CheckBox->Location = System::Drawing::Point(483, 302);
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
			this->Password_Textbox->Location = System::Drawing::Point(329, 236);
			this->Password_Textbox->Name = L"Password_Textbox";
			this->Password_Textbox->Size = System::Drawing::Size(348, 26);
			this->Password_Textbox->TabIndex = 8;
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label8->Location = System::Drawing::Point(29, 278);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(322, 41);
			this->label8->TabIndex = 6;
			this->label8->Text = L" For 2 step verification";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semibold", 18));
			this->label9->Location = System::Drawing::Point(29, 218);
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
			this->Save_button->Location = System::Drawing::Point(166, 3);
			this->Save_button->Name = L"Save_button";
			this->Save_button->Size = System::Drawing::Size(157, 179);
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
			this->pictureBox2->Location = System::Drawing::Point(79, 12);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(116, 119);
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
			this->panel1->Size = System::Drawing::Size(329, 715);
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
			this->tableLayoutPanel1->Size = System::Drawing::Size(326, 185);
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
			this->Logout_button->Size = System::Drawing::Size(157, 179);
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
			this->Notification_button->Size = System::Drawing::Size(329, 119);
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
			this->Security_button->Size = System::Drawing::Size(329, 119);
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
			this->Account_button->Size = System::Drawing::Size(329, 119);
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
			this->panel2->Size = System::Drawing::Size(329, 177);
			this->panel2->TabIndex = 0;
			// 
			// Hello_label
			// 
			this->Hello_label->AutoSize = true;
			this->Hello_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Hello_label->Location = System::Drawing::Point(44, 145);
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
			this->Current_Tab_label->Location = System::Drawing::Point(692, 12);
			this->Current_Tab_label->Name = L"Current_Tab_label";
			this->Current_Tab_label->Size = System::Drawing::Size(154, 42);
			this->Current_Tab_label->TabIndex = 0;
			this->Current_Tab_label->Text = L"Account";
			// 
			// Account_Settings
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::HotTrack;
			this->ClientSize = System::Drawing::Size(1204, 715);
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
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
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
}
private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
	save();
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
	if(Logoutkey=='0'){
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
	System::Windows::Forms::DialogResult Logout_result = MessageBox::Show("Are you sure you want to Logout & save Current changes?", "Logout?", MessageBoxButtons::YesNoCancel, MessageBoxIcon::Question);
	if (Logout_result == System::Windows::Forms::DialogResult::Yes) {
		//Save_button->PerformClick();
		save();
		Logoutkey = 'b';
		this->Close();
	}
	else if(Logout_result == System::Windows::Forms::DialogResult::No) {
		Logoutkey = 'n';
		this->Close();
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
};
}
