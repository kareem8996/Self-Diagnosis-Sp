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

namespace Project38{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm2
	/// </summary>
	public ref class MyForm2 : public System::Windows::Forms::Form
	{
	public:

		String ^ GetPass() {
			return textBox3->Text ;
		}

		MyForm2(string code,string name, string pass)
		{
			InitializeComponent();
			String^ Ver = gcnew String(code.c_str());
			String^ u = gcnew String(name.c_str());
			String^ a = gcnew String(pass.c_str());
			label3->Text = Ver;
			label5->Text = u;
			label6->Text = a;
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Label^ label6;

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
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(158, 52);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(109, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Verification Code";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(158, 145);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(42, 17);
			this->label2->TabIndex = 1;
			this->label2->Text = L"E-Mail";
			this->label2->Click += gcnew System::EventHandler(this, &MyForm2::label2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(161, 87);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(183, 24);
			this->textBox1->TabIndex = 2;
			this->textBox1->KeyPress += gcnew System::Windows::Forms::KeyPressEventHandler(this, &MyForm2::textBox1_KeyPress);
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(161, 181);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(183, 24);
			this->textBox2->TabIndex = 3;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm2::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(198, 232);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(103, 39);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Verify";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm2::button1_Click);
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(475, -1);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(42, 17);
			this->label3->TabIndex = 5;
			this->label3->Text = L"label3";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(158, 22);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(42, 17);
			this->label4->TabIndex = 6;
			this->label4->Text = L"label4";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(475, -1);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(42, 17);
			this->label5->TabIndex = 7;
			this->label5->Text = L"label5";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(161, 87);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(183, 24);
			this->textBox3->TabIndex = 8;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(475, -1);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(42, 17);
			this->label6->TabIndex = 9;
			this->label6->Text = L"label6";
			// 
			// MyForm2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(7, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(529, 373);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm2";
			this->ShowInTaskbar = false;
			this->Text = L"MyForm2";
			this->Load += gcnew System::EventHandler(this, &MyForm2::MyForm2_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label2_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		if (button1->Text == "Verify") {
			if (textBox1->Text != "") {
				if (label1->Text == "Verification Code") {
					if (textBox1->Text == label3->Text) {
						label1->Text = "Enter Password";
						label2->Show();
						label2->Text = "Renter Password";
						textBox2->Show();
						label4->Hide();
						textBox3->Show();
						textBox1->Text = "";
						textBox1->Hide();
						textBox3->Show();
						button1->Text = "Enter";
					}
					else {
						label4->Text = "Verification Invalid";
						label4->Show();
					}

				}
				
			}
		}
		else {
			if (label1->Text == "Enter Password") {
			if (textBox2->Text != "") {
				if (textBox3->Text == textBox2->Text) {
					if (textBox3->Text != label5->Text) {
						if (textBox3->Text != label6->Text) {
							label4->Hide();
							this->Close();
						}
						else {
							label4->Show();
							label4->Text = "This password is an old password ";
						}
					}
					else {
						label4->Text = "Password cannot be the same as the Username";
						label4->Show();
					}
				}
				else {
					label4->Text = "Passwords do not match";
					label4->Show();
				}
			}
				}

		}
		
	}
private: System::Void MyForm2_Load(System::Object^ sender, System::EventArgs^ e) {
	label3->Hide();
	label2->Hide();
	textBox2->Hide();
	textBox3->Hide();
	label4-> Hide();
	label5->Hide();
	label6->Hide();
}
private: System::Void textBox1_KeyPress(System::Object^ sender, System::Windows::Forms::KeyPressEventArgs^ e) {
	char ch = e->KeyChar;
	if (!isdigit(ch) && ch != 8)
	{
		e->Handled = true;
	}
}
};
}
