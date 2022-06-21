#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
[STAThreadAttribute]
void main(cli::array<String^>^ args) {
	Application::SetCompatibleTextRenderingDefault(false);
	Application::EnableVisualStyles();
	Project38::MyForm frm;
	Application::Run(% frm);

}
