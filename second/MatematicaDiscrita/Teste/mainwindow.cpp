#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QMessageBox>
#include<qlayout.h>
#include <qfile.h>
#include <QFileDialog>

struct Student {
    QString nomeAluno;
    QString nomeDisciplina;
    float notaN1P;
    float notaN2P;
    float notaN1S;
    float notaN2S;
    float notaSubstitutiva;
    Student* next;
};
Student* head = nullptr;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButtonCheckTest_clicked()
{
    QString nomeAluno =ui->lineEditUsername->text();
    QString nomeDisciplina = ui->comboBoxDiscipline->currentText();
    float notaN1P = ui->lineEdit_n1First->text().toFloat();
    float notaN2P = ui->lineEdit_n2First->text().toFloat();
    float notaN1S = ui->lineEdit_n1Second->text().toFloat();
    float notaN2S = ui->lineEdit_n2Second->text().toFloat();

    float mediaP = (notaN1P + notaN2P)/2;
    float mediaS = (notaN1S + notaN2S)/2;

    if ((mediaP > 2 && mediaP < 6) || (mediaS > 2 && mediaP < 6)) {
        QDialog dialog(this);
        dialog.setWindowTitle("Nota da Substitutiva");

        // Criar um QLineEdit para a nota da substitutiva
        QLineEdit *lineEditNotaSubstitutiva = new QLineEdit(&dialog);

        // Criar um layout para o diálogo
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(lineEditNotaSubstitutiva);

        // Adicionar botões Ok e Cancelar
        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        layout->addWidget(buttonBox);

        // Conectar o sinal do botão Ok ao slot do diálogo
        connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

        // Definir o layout do diálogo
        dialog.setLayout(layout);

        // Executar o diálogo
        if (dialog.exec() == QDialog::Accepted) {
            // Obter a nota da substitutiva digitada
            float notaSubstitutiva = lineEditNotaSubstitutiva->text().toFloat();

            // Verificar qual semestre o aluno escolheu


            if (notaSubstitutiva > 10 || notaSubstitutiva > 10 || notaSubstitutiva > 10 || notaSubstitutiva > 10)
                QMessageBox::warning(this, "Erro", "Impossível calcular substitutiva, digite um número válido");
                notaSubstitutiva = 0;
            }
    }else{
        QMessageBox::warning(this, "Erro", "Impossível calcular substitutiva. Pois sua média é de não se encaixa nas regras");
    }
 }


void MainWindow::on_pushButtonAddStudent_clicked()
{
    QString nomeAluno = ui->lineEditUsername->text();
    QString nomeDisciplina = ui->comboBoxDiscipline->currentText();
    float notaN1P = ui->lineEdit_n1First->text().toFloat();
    float notaN2P = ui->lineEdit_n2First->text().toFloat();
    float notaN1S = ui->lineEdit_n1Second->text().toFloat();
    float notaN2S = ui->lineEdit_n2Second->text().toFloat();

    // Create a new student node
    Student* newNode = new Student;
    newNode->nomeAluno = nomeAluno;
    newNode->nomeDisciplina = nomeDisciplina;
    newNode->notaN1P = notaN1P;
    newNode->notaN2P = notaN2P;
    newNode->notaN1S = notaN1S;
    newNode->notaN2S = notaN2S;
    newNode->next = nullptr;

    // Add the new node to the linked list
    if (head == nullptr) {
        head = newNode;
    } else {
        Student* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }
}


void MainWindow::on_pushButtonPrint_clicked(){
    QFileDialog fileDialog(this, "Salvar arquivo CSV", "", "CSV files (*.csv)");
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    if (fileDialog.exec() == QDialog::Accepted) {
        QString filePath = fileDialog.selectedFiles().first();
        // Create a file stream to write to the file
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Erro", "Não foi possível criar o arquivo CSV");
            return;
        }

        // Create a text stream to write to the file
        QTextStream stream(&file);
    // Write the student list to the CSV file
    Student* current = head;
    while (current != nullptr) {
        // Calculate the average
        float mediaP = (current->notaN1P + current->notaN2P) / 2;
        float mediaS = (current->notaN1S + current->notaN2S) / 2;
        float media = (mediaP + mediaS) / 2;

        // Check if the student did a substitution
        float notaSubstitutiva = current->notaSubstitutiva;
        if (notaSubstitutiva != 0) {
            // Substitute the lowest grade
            if (current->notaN1P < current->notaN2P) {
                current->notaN1P = notaSubstitutiva;
            } else {
                current->notaN2P = notaSubstitutiva;
            }
            mediaP = (current->notaN1P + current->notaN2P) / 2;
            media = (mediaP + mediaS) / 2;
        }

        // Check the student's situation
        QString situacao;
        if (media >= 6) {
            situacao = "Aprovado";
        } else {
            situacao = "Reprovado";
        }

        // Write the student row to the CSV file
        stream << current->nomeAluno << "," << current->nomeDisciplina << "," << current->notaN1P << "," << current->notaN2P << "," << current->notaN1S << "," << current->notaN2S << "," << notaSubstitutiva << "," << media << "," << situacao << "\n";

        // Move to the next student
        current = current->next;
    }

    // Close the file
    file.close();
}
}
