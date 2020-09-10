#pragma once
//#include <iostream>
#include <ctime>
#include <fstream>
#include "SortedSequence.h"
#include "Dictionary.h"
#include "PlotHistogram.h"
#include "OperationsOnSparseMatrices.h"
#include "AdditionalDataTypes.h"

namespace LaboratoryWork23 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}
	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^  chart1;
	protected:
	private: System::Windows::Forms::GroupBox^  groupBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::ComboBox^  comboBox3;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::TextBox^  textBox5;
	private: System::Windows::Forms::TextBox^  textBox7;
	private: System::Windows::Forms::TextBox^  textBox6;
	private: System::Windows::Forms::Label^  label11;
	private: System::Windows::Forms::Label^  label10;
	private: System::Windows::Forms::GroupBox^  groupBox2;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::TextBox^  textBox14;
	private: System::Windows::Forms::Label^  label19;




	private: System::Windows::Forms::TextBox^  textBox13;
	private: System::Windows::Forms::TextBox^  textBox12;
	private: System::Windows::Forms::Label^  label18;







	private: System::Windows::Forms::TextBox^  textBox11;
	private: System::Windows::Forms::Label^  label16;





	private: System::Windows::Forms::Label^  label12;
	private: System::Windows::Forms::TextBox^  textBox8;
	private: System::Windows::Forms::Label^  label13;
	private: System::Windows::Forms::TextBox^  textBox9;
	private: System::Windows::Forms::TextBox^  textBox10;
	private: System::Windows::Forms::Label^  label15;
	private: System::Windows::Forms::Label^  label14;
	private: System::Windows::Forms::Label^  label17;
	private: System::Windows::Forms::GroupBox^  groupBox3;


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;
#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^  chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^  legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^  series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
			this->textBox7 = (gcnew System::Windows::Forms::TextBox());
			this->textBox6 = (gcnew System::Windows::Forms::TextBox());
			this->label11 = (gcnew System::Windows::Forms::Label());
			this->label10 = (gcnew System::Windows::Forms::Label());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->comboBox3 = (gcnew System::Windows::Forms::ComboBox());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
			this->label17 = (gcnew System::Windows::Forms::Label());
			this->label15 = (gcnew System::Windows::Forms::Label());
			this->label14 = (gcnew System::Windows::Forms::Label());
			this->textBox10 = (gcnew System::Windows::Forms::TextBox());
			this->textBox9 = (gcnew System::Windows::Forms::TextBox());
			this->label13 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox14 = (gcnew System::Windows::Forms::TextBox());
			this->label19 = (gcnew System::Windows::Forms::Label());
			this->textBox13 = (gcnew System::Windows::Forms::TextBox());
			this->textBox12 = (gcnew System::Windows::Forms::TextBox());
			this->label18 = (gcnew System::Windows::Forms::Label());
			this->textBox11 = (gcnew System::Windows::Forms::TextBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->label12 = (gcnew System::Windows::Forms::Label());
			this->textBox8 = (gcnew System::Windows::Forms::TextBox());
			this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			this->groupBox1->SuspendLayout();
			this->groupBox2->SuspendLayout();
			this->SuspendLayout();
			// 
			// chart1
			// 
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(12, 12);
			this->chart1->Name = L"chart1";
			series1->ChartArea = L"ChartArea1";
			series1->Legend = L"Legend1";
			series1->Name = L"Series1";
			this->chart1->Series->Add(series1);
			this->chart1->Size = System::Drawing::Size(975, 600);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"chart1";
			// 
			// groupBox1
			// 
			this->groupBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox1.BackgroundImage")));
			this->groupBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->groupBox1->Controls->Add(this->textBox7);
			this->groupBox1->Controls->Add(this->textBox6);
			this->groupBox1->Controls->Add(this->label11);
			this->groupBox1->Controls->Add(this->label10);
			this->groupBox1->Controls->Add(this->textBox5);
			this->groupBox1->Controls->Add(this->label9);
			this->groupBox1->Controls->Add(this->comboBox3);
			this->groupBox1->Controls->Add(this->label8);
			this->groupBox1->Controls->Add(this->label1);
			this->groupBox1->Controls->Add(this->comboBox1);
			this->groupBox1->Controls->Add(this->label2);
			this->groupBox1->Controls->Add(this->textBox1);
			this->groupBox1->Controls->Add(this->label3);
			this->groupBox1->Controls->Add(this->label4);
			this->groupBox1->Controls->Add(this->textBox2);
			this->groupBox1->Controls->Add(this->label5);
			this->groupBox1->Controls->Add(this->textBox3);
			this->groupBox1->Controls->Add(this->label6);
			this->groupBox1->Controls->Add(this->textBox4);
			this->groupBox1->Controls->Add(this->label7);
			this->groupBox1->Controls->Add(this->comboBox2);
			this->groupBox1->Controls->Add(this->button1);
			this->groupBox1->Location = System::Drawing::Point(993, 12);
			this->groupBox1->Name = L"groupBox1";
			this->groupBox1->Size = System::Drawing::Size(377, 600);
			this->groupBox1->TabIndex = 1;
			this->groupBox1->TabStop = false;
			this->groupBox1->Text = L"Входные данные";
			// 
			// textBox7
			// 
			this->textBox7->Location = System::Drawing::Point(191, 455);
			this->textBox7->Name = L"textBox7";
			this->textBox7->Size = System::Drawing::Size(150, 22);
			this->textBox7->TabIndex = 21;
			this->textBox7->Visible = false;
			// 
			// textBox6
			// 
			this->textBox6->Location = System::Drawing::Point(6, 455);
			this->textBox6->Name = L"textBox6";
			this->textBox6->Size = System::Drawing::Size(150, 22);
			this->textBox6->TabIndex = 20;
			this->textBox6->Visible = false;
			// 
			// label11
			// 
			this->label11->AutoSize = true;
			this->label11->Location = System::Drawing::Point(191, 430);
			this->label11->Name = L"label11";
			this->label11->Size = System::Drawing::Size(13, 17);
			this->label11->TabIndex = 19;
			this->label11->Text = L"-";
			this->label11->Visible = false;
			// 
			// label10
			// 
			this->label10->AutoSize = true;
			this->label10->Location = System::Drawing::Point(6, 430);
			this->label10->Name = L"label10";
			this->label10->Size = System::Drawing::Size(13, 17);
			this->label10->TabIndex = 18;
			this->label10->Text = L"-";
			this->label10->Visible = false;
			// 
			// textBox5
			// 
			this->textBox5->Location = System::Drawing::Point(6, 560);
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(150, 22);
			this->textBox5->TabIndex = 17;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Location = System::Drawing::Point(6, 535);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(224, 17);
			this->label9->TabIndex = 16;
			this->label9->Text = L"Время построения гистограммы:";
			// 
			// comboBox3
			// 
			this->comboBox3->FormattingEnabled = true;
			this->comboBox3->Items->AddRange(gcnew cli::array< System::Object^  >(4) {
				L"пополам", L"в соответствии с золотым сечением",
					L"в соответствии с парой натуральных чисел", L"в соответствии с парой чисел в последовательности Фибоначчи"
			});
			this->comboBox3->Location = System::Drawing::Point(6, 390);
			this->comboBox3->Name = L"comboBox3";
			this->comboBox3->Size = System::Drawing::Size(365, 24);
			this->comboBox3->TabIndex = 15;
			this->comboBox3->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::comboBox3_SelectedIndexChanged);
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(6, 365);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(254, 17);
			this->label8->TabIndex = 14;
			this->label8->Text = L"Тип разбиения последовательности:";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(6, 40);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(89, 17);
			this->label1->TabIndex = 12;
			this->label1->Text = L"Тип данных:";
			// 
			// comboBox1
			// 
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"int" });
			this->comboBox1->Location = System::Drawing::Point(6, 65);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(150, 24);
			this->comboBox1->TabIndex = 13;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(6, 105);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(164, 17);
			this->label2->TabIndex = 0;
			this->label2->Text = L"Количество элементов:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(6, 130);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(150, 22);
			this->textBox1->TabIndex = 3;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(6, 170);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(145, 17);
			this->label3->TabIndex = 2;
			this->label3->Text = L"Диапазон значений:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(6, 198);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(23, 17);
			this->label4->TabIndex = 9;
			this->label4->Text = L"от";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(35, 195);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(150, 22);
			this->textBox2->TabIndex = 5;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Location = System::Drawing::Point(191, 198);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(24, 17);
			this->label5->TabIndex = 10;
			this->label5->Text = L"до";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(221, 195);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(150, 22);
			this->textBox3->TabIndex = 7;
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Location = System::Drawing::Point(6, 235);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(258, 17);
			this->label6->TabIndex = 4;
			this->label6->Text = L"Количество диапазонов в разбиении:";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(6, 260);
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(150, 22);
			this->textBox4->TabIndex = 8;
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Location = System::Drawing::Point(6, 300);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(187, 17);
			this->label7->TabIndex = 6;
			this->label7->Text = L"Тип разбиения диапазона:";
			// 
			// comboBox2
			// 
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Items->AddRange(gcnew cli::array< System::Object^  >(1) { L"равномерное разбиение" });
			this->comboBox2->Location = System::Drawing::Point(6, 325);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(365, 24);
			this->comboBox2->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(6, 495);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(200, 23);
			this->button1->TabIndex = 11;
			this->button1->Text = L"Построить гистограмму";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// groupBox2
			// 
			this->groupBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->groupBox2->Controls->Add(this->label17);
			this->groupBox2->Controls->Add(this->label15);
			this->groupBox2->Controls->Add(this->label14);
			this->groupBox2->Controls->Add(this->textBox10);
			this->groupBox2->Controls->Add(this->textBox9);
			this->groupBox2->Controls->Add(this->label13);
			this->groupBox2->Controls->Add(this->button2);
			this->groupBox2->Controls->Add(this->textBox14);
			this->groupBox2->Controls->Add(this->label19);
			this->groupBox2->Controls->Add(this->textBox13);
			this->groupBox2->Controls->Add(this->textBox12);
			this->groupBox2->Controls->Add(this->label18);
			this->groupBox2->Controls->Add(this->textBox11);
			this->groupBox2->Controls->Add(this->label16);
			this->groupBox2->Controls->Add(this->label12);
			this->groupBox2->Controls->Add(this->textBox8);
			this->groupBox2->Location = System::Drawing::Point(12, 618);
			this->groupBox2->Name = L"groupBox2";
			this->groupBox2->Size = System::Drawing::Size(1076, 223);
			this->groupBox2->TabIndex = 2;
			this->groupBox2->TabStop = false;
			this->groupBox2->Text = L"Обработка разреженных матриц";
			// 
			// label17
			// 
			this->label17->AutoSize = true;
			this->label17->Location = System::Drawing::Point(754, 68);
			this->label17->Name = L"label17";
			this->label17->Size = System::Drawing::Size(20, 17);
			this->label17->TabIndex = 33;
			this->label17->Text = L"%";
			// 
			// label15
			// 
			this->label15->AutoSize = true;
			this->label15->Location = System::Drawing::Point(388, 68);
			this->label15->Name = L"label15";
			this->label15->Size = System::Drawing::Size(24, 17);
			this->label15->TabIndex = 32;
			this->label15->Text = L"до";
			// 
			// label14
			// 
			this->label14->AutoSize = true;
			this->label14->Location = System::Drawing::Point(203, 68);
			this->label14->Name = L"label14";
			this->label14->Size = System::Drawing::Size(23, 17);
			this->label14->TabIndex = 31;
			this->label14->Text = L"от";
			// 
			// textBox10
			// 
			this->textBox10->Location = System::Drawing::Point(418, 65);
			this->textBox10->Name = L"textBox10";
			this->textBox10->Size = System::Drawing::Size(150, 22);
			this->textBox10->TabIndex = 30;
			// 
			// textBox9
			// 
			this->textBox9->Location = System::Drawing::Point(232, 65);
			this->textBox9->Name = L"textBox9";
			this->textBox9->Size = System::Drawing::Size(150, 22);
			this->textBox9->TabIndex = 29;
			// 
			// label13
			// 
			this->label13->AutoSize = true;
			this->label13->Location = System::Drawing::Point(203, 40);
			this->label13->Name = L"label13";
			this->label13->Size = System::Drawing::Size(145, 17);
			this->label13->TabIndex = 28;
			this->label13->Text = L"Диапазон значений:";
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(6, 105);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(300, 23);
			this->button2->TabIndex = 27;
			this->button2->Text = L"Вычислить линейную комбинацию";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// textBox14
			// 
			this->textBox14->Location = System::Drawing::Point(6, 170);
			this->textBox14->Name = L"textBox14";
			this->textBox14->Size = System::Drawing::Size(150, 22);
			this->textBox14->TabIndex = 26;
			// 
			// label19
			// 
			this->label19->AutoSize = true;
			this->label19->Location = System::Drawing::Point(6, 145);
			this->label19->Name = L"label19";
			this->label19->Size = System::Drawing::Size(290, 17);
			this->label19->TabIndex = 25;
			this->label19->Text = L"Время вычисления линейной комбинации:";
			// 
			// textBox13
			// 
			this->textBox13->Location = System::Drawing::Point(918, 65);
			this->textBox13->Name = L"textBox13";
			this->textBox13->Size = System::Drawing::Size(120, 22);
			this->textBox13->TabIndex = 24;
			// 
			// textBox12
			// 
			this->textBox12->Location = System::Drawing::Point(792, 65);
			this->textBox12->Name = L"textBox12";
			this->textBox12->Size = System::Drawing::Size(120, 22);
			this->textBox12->TabIndex = 23;
			// 
			// label18
			// 
			this->label18->AutoSize = true;
			this->label18->Location = System::Drawing::Point(789, 40);
			this->label18->Name = L"label18";
			this->label18->Size = System::Drawing::Size(267, 17);
			this->label18->TabIndex = 22;
			this->label18->Text = L"Коэффициенты линейной комбинации:";
			// 
			// textBox11
			// 
			this->textBox11->Location = System::Drawing::Point(598, 65);
			this->textBox11->Name = L"textBox11";
			this->textBox11->Size = System::Drawing::Size(150, 22);
			this->textBox11->TabIndex = 21;
			// 
			// label16
			// 
			this->label16->AutoSize = true;
			this->label16->Location = System::Drawing::Point(595, 40);
			this->label16->Name = L"label16";
			this->label16->Size = System::Drawing::Size(188, 17);
			this->label16->TabIndex = 20;
			this->label16->Text = L"Коэффициент заполнения:";
			// 
			// label12
			// 
			this->label12->AutoSize = true;
			this->label12->Location = System::Drawing::Point(6, 40);
			this->label12->Name = L"label12";
			this->label12->Size = System::Drawing::Size(69, 17);
			this->label12->TabIndex = 19;
			this->label12->Text = L"Порядок:";
			// 
			// textBox8
			// 
			this->textBox8->Location = System::Drawing::Point(6, 65);
			this->textBox8->Name = L"textBox8";
			this->textBox8->Size = System::Drawing::Size(150, 22);
			this->textBox8->TabIndex = 18;
			// 
			// groupBox3
			// 
			this->groupBox3->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groupBox3.BackgroundImage")));
			this->groupBox3->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->groupBox3->Location = System::Drawing::Point(1095, 619);
			this->groupBox3->Name = L"groupBox3";
			this->groupBox3->Size = System::Drawing::Size(275, 222);
			this->groupBox3->TabIndex = 3;
			this->groupBox3->TabStop = false;
			this->groupBox3->Text = L"Автор работы";
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::GradientInactiveCaption;
			this->ClientSize = System::Drawing::Size(1382, 853);
			this->Controls->Add(this->groupBox3);
			this->Controls->Add(this->groupBox2);
			this->Controls->Add(this->groupBox1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"LaboratoryWork2.3";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			this->groupBox1->ResumeLayout(false);
			this->groupBox1->PerformLayout();
			this->groupBox2->ResumeLayout(false);
			this->groupBox2->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
		chart1->Series["Series1"]->Points->Clear();
		int NumberOfItems = Convert::ToInt32(textBox1->Text);
		int NumberOfRanges = Convert::ToInt32(textBox4->Text);
		double(*Coefficient)(int, int);
		switch (comboBox2->SelectedIndex) {
		case 0:
			Coefficient = UniformPartitionCoefficient;
			break;
		}
		double LeftShare;
		double RightShare;
		switch (comboBox3->SelectedIndex) {
		case 0:
			LeftShare = 1;
			RightShare = 1;
			break;
		case 1:
			LeftShare = 1236067977;
			RightShare = 2000000000;
			break;
		case 2:
			LeftShare = Convert::ToInt32(textBox6->Text);
			RightShare = Convert::ToInt32(textBox7->Text);
			break;
		case 3:
			LeftShare = FibonacciNumber(Convert::ToInt32(textBox6->Text));
			RightShare = FibonacciNumber(Convert::ToInt32(textBox6->Text) + 1);
			break;
		}
		switch (comboBox1->SelectedIndex) {
		case 0:
			ArraySortedSequence<int> *Sequence = new ArraySortedSequence<int>();
			BinaryTreeDictionary<Range<int>, int> *HistogramDictionary = new BinaryTreeDictionary<Range<int>, int>();
			Int32 Left = Convert::ToInt32(textBox2->Text);
			Int32 Right = Convert::ToInt32(textBox3->Text);
			int *Auxiliary = NULL;
			for (int i = 1; i <= NumberOfItems; i++) {
				Sequence->Add(Left + Random0(Right - Left, Auxiliary));
			}
			int StartTime = clock();
			HistogramDictionary = PlotHistogram<int>(Sequence, Left, Right, NumberOfRanges, Coefficient, LeftShare, RightShare);
			int EndTime = clock();
			textBox5->Text = Convert::ToString(EndTime - StartTime) + " мс";
			for (int i = 1; i <= HistogramDictionary->GetCount(); i++) {
				Range<int> Key = { (int)(Left + Coefficient(i - 1, NumberOfRanges) * (Right - Left)), (int)(Left + Coefficient(i, NumberOfRanges) * (Right - Left)) };
				int Value = HistogramDictionary->Get(Key);
				chart1->Series["Series1"]->Points->AddXY(i, Value);
			}
			break;
		}
	}
private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
	int MatrixOrder = Convert::ToInt32(textBox8->Text);
	int Left = Convert::ToInt32(textBox9->Text);
	int Right = Convert::ToInt32(textBox10->Text);
	int FillFactor = Convert::ToInt32(textBox11->Text);
	int Coefficient1 = Convert::ToInt32(textBox12->Text);
	int Coefficient2 = Convert::ToInt32(textBox13->Text);
	IndexCouple Key;
	int *Auxiliary = NULL;
	BinaryTreeDictionary<IndexCouple, int> *SparseMatrix1 = new BinaryTreeDictionary<IndexCouple, int>();
	for (int i = 1; i <= MatrixOrder * MatrixOrder * FillFactor / 100; i++) {
		Key = { Random0(MatrixOrder, Auxiliary), Random0(MatrixOrder, Auxiliary) };
		if (SparseMatrix1->ContainsKey(Key) == false) {
			SparseMatrix1->Add(Key, Left + Random0(Right - Left, Auxiliary));
		}
	}
	BinaryTreeDictionary<IndexCouple, int> *SparseMatrix2 = new BinaryTreeDictionary<IndexCouple, int>();
	for (int i = 1; i <= MatrixOrder * MatrixOrder * FillFactor / 100; i++) {
		Key = { Random0(MatrixOrder, Auxiliary), Random0(MatrixOrder, Auxiliary) };
		if (SparseMatrix2->ContainsKey(Key) == false) {
			SparseMatrix2->Add(Key, Left + Random0(Right - Left, Auxiliary));
		}
	}
	int Time = 0;
	int StartTime = clock();
	BinaryTreeDictionary<IndexCouple, int> *SparseMatrix = LinearCombination(&Time, SparseMatrix1, Coefficient1, SparseMatrix2, Coefficient2);
	int EndTime = clock();
	textBox14->Text = Convert::ToString(EndTime - StartTime) + " мс";
	//textBox14->Text = /*Convert::ToString(Time) + ", " + */Convert::ToString(EndTime - StartTime);
	std::ofstream File;
	File.open("C:\\Users\\lenovo\\Desktop\\Лабораторные работы по информатике\\LaboratoryWork2.3 последняя версия\\LaboratoryWork2.3\\File.txt");
	File << "SparseMatrix1:\n";
	File << SparseMatrix1->BinaryDictionaryToString();
	File << "SparseMatrix2:\n";
	File << SparseMatrix2->BinaryDictionaryToString();
	File << "SparseMatrix:\n";
	File << SparseMatrix->BinaryDictionaryToString();
	File.close();
}
private: System::Void comboBox3_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
	switch (comboBox3->SelectedIndex) {
	case 0:
		label10->Text = "";
		label11->Text = "";
		label10->Visible = false;
		label11->Visible = false;
		textBox6->Visible = false;
		textBox7->Visible = false;
		break;
	case 1:
		label10->Text = "";
		label11->Text = "";
		label10->Visible = false;
		label11->Visible = false;
		textBox6->Visible = false;
		textBox7->Visible = false;
		break;
	case 2:
		label10->Text = "Левая доля:";
		label11->Text = "Правая доля:";
		label10->Visible = true;
		label11->Visible = true;
		textBox6->Visible = true;
		textBox7->Visible = true;
		break;
	case 3:
		label10->Text = "Индекс пары чисел последовательности Фибоначчи:";
		label11->Text = "";
		label10->Visible = true;
		label11->Visible = false;
		textBox6->Visible = true;
		textBox7->Visible = false;
		break;
	}
}
};
}
