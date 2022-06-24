#pragma once
#include <iostream>
#include <string>
#include <conio.h>
#include <stdio.h>   
#include<vector>
#include <Windows.h>
#include <time.h>
#include <fstream>
#include <signal.h> 
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
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Camera_winform
	/// </summary>
	public ref class Camera_winform : public System::Windows::Forms::Form
	{
	public:
		void MarshalString(String^ s, string& os) {
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		}
		Camera^ MyCamera = gcnew Camera();
		Camera_winform(string username)
		{
			InitializeComponent();
			String^ uname = gcnew String(username.c_str());
			Username_label->Text = uname;
			MyCamera->OnFrameArrived += gcnew FrameArrivedEventHandler(this, &Camera_winform::MyCamera_OnFrameArrived);
			MyCamera->Start(0);
			Username_label->Hide();
			//
			//TODO: Add the constructor code here
			//
		}
		void MyCamera_OnFrameArrived(Object^ source, FrameArrivedEventArgs^ e) {
			Image^ img = e->GetFrame();
			pictureBox1->Image = img;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Camera_winform()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	protected:

	private: System::Windows::Forms::Button^ Capture_button;
	private: System::Windows::Forms::Label^ Username_label;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->Capture_button = (gcnew System::Windows::Forms::Button());
			this->Username_label = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Location = System::Drawing::Point(121, 21);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(560, 349);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// Capture_button
			// 
			this->Capture_button->Location = System::Drawing::Point(322, 388);
			this->Capture_button->Name = L"Capture_button";
			this->Capture_button->Size = System::Drawing::Size(119, 41);
			this->Capture_button->TabIndex = 2;
			this->Capture_button->Text = L"Capture";
			this->Capture_button->UseVisualStyleBackColor = true;
			this->Capture_button->Click += gcnew System::EventHandler(this, &Camera_winform::Capture_button_Click);
			// 
			// Username_label
			// 
			this->Username_label->AutoSize = true;
			this->Username_label->Location = System::Drawing::Point(724, 17);
			this->Username_label->Name = L"Username_label";
			this->Username_label->Size = System::Drawing::Size(10, 16);
			this->Username_label->TabIndex = 3;
			this->Username_label->Text = L" ";
			// 
			// Camera_winform
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(811, 471);
			this->Controls->Add(this->Username_label);
			this->Controls->Add(this->Capture_button);
			this->Controls->Add(this->pictureBox1);
			this->Name = L"Camera_winform";
			this->Text = L"Camera_winform";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &Camera_winform::Camera_winform_FormClosing);
			this->Load += gcnew System::EventHandler(this, &Camera_winform::Camera_winform_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Camera_winform_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void Capture_button_Click(System::Object^ sender, System::EventArgs^ e) {
		if (Capture_button->Text == "Capture"){
			MyCamera->Stop();
			string username;
			MarshalString(Username_label->Text, username);
			string wow = "PICs\\" + username + ".jpg";
			String^ str3 = gcnew String(wow.c_str());
			pictureBox1->Image->Save(str3, ImageFormat::Jpeg);
			Capture_button->Text = "Retake";
		}
		else {
			MyCamera->Start(0);
			Capture_button->Text = "Capture";
		}
	}
	private: System::Void Save_button_Click(System::Object^ sender, System::EventArgs^ e) {
		
	}
private: System::Void Camera_winform_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
	MyCamera->Stop();
}
};
}
