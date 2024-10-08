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
    // Obter os valores de entrada do primeiro semestre
    float notaN1P = ui->lineEdit_n1First->text().toFloat();
    float notaN2P = ui->lineEdit_n2First->text().toFloat();

    // Calcular a média do primeiro semestre
    float mediaP = (notaN1P + notaN2P) / 2;

    // Verificar se a média do primeiro semestre está entre 2 e 6
    if (mediaP >= 2 && mediaP < 6) {
        QDialog dialog(this);
        dialog.setWindowTitle("Nota da Substitutiva - Primeiro Semestre");

        // Criar um QLineEdit para a nota substitutiva
        QLineEdit *lineEditNotaSubstitutiva = new QLineEdit(&dialog);
        lineEditNotaSubstitutiva->setPlaceholderText("Insira a nota da substitutiva");

        // Criar um layout para o diálogo
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(lineEditNotaSubstitutiva);

        // Adicionar botões Ok e Cancelar
        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        layout->addWidget(buttonBox);

        // Conectar os sinais dos botões Ok e Cancelar
        connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

        // Definir o layout do diálogo
        dialog.setLayout(layout);

        // Executar o diálogo e pegar a nota da substitutiva
        if (dialog.exec() == QDialog::Accepted) {
            float notaSubstitutiva = lineEditNotaSubstitutiva->text().toFloat();

            // Verificar se a nota substitutiva é válida
            if (notaSubstitutiva > 10 || notaSubstitutiva < 0) {
                QMessageBox::warning(this, "Erro", "Impossível calcular substitutiva, digite um número válido entre 0 e 10.");
                return;
            }

            // Substituir a menor nota (entre N1P e N2P) pela nota substitutiva se ela for maior
            if (notaSubstitutiva > notaN1P && notaN1P <= notaN2P) {
                // Substitui notaN1P pela substitutiva e atualiza o input
                notaN1P = notaSubstitutiva;
                ui->lineEdit_n1First->setText(QString::number(notaN1P));
            } else if (notaSubstitutiva > notaN2P && notaN2P <= notaN1P) {
                // Substitui notaN2P pela substitutiva e atualiza o input
                notaN2P = notaSubstitutiva;
                ui->lineEdit_n2First->setText(QString::number(notaN2P));
            }

            // Recalcular a média após a substituição
            mediaP = (notaN1P + notaN2P) / 2;

            // Exibir a nova média do primeiro semestre
            QString resultado = QString("Nova média do Primeiro Semestre: %1").arg(mediaP);
            QMessageBox::information(this, "Resultado", resultado);
        }
    } else {
        // Exibir mensagem de erro se a média do primeiro semestre não estiver dentro das regras
        QMessageBox::warning(this, "Erro", "Impossível calcular substitutiva. Sua média do primeiro semestre não se encaixa nas regras (entre 2 e 6).");
    }
}


void MainWindow::on_pushButtonAddStudent_clicked()
{
    // Obter os valores de entrada
    QString nomeAluno = ui->lineEditUsername->text();
    QString nomeDisciplina = ui->comboBoxDiscipline->currentText();
    float notaN1P = ui->lineEdit_n1First->text().toFloat();
    float notaN2P = ui->lineEdit_n2First->text().toFloat();
    float notaN1S = ui->lineEdit_n1Second->text().toFloat();
    float notaN2S = ui->lineEdit_n2Second->text().toFloat();

    // Verificar se o nome do aluno e a disciplina estão preenchidos
    if (nomeAluno.isEmpty() || nomeDisciplina.isEmpty()) {
        QMessageBox::warning(this, "Erro", "Não foi possível cadastrar o aluno. Verifique se todos os campos estão preenchidos corretamente.");
        return;
    }

    // Criar um novo nó do aluno
    Student* newNode = new Student;
    newNode->nomeAluno = nomeAluno;
    newNode->nomeDisciplina = nomeDisciplina;
    newNode->notaN1P = notaN1P;
    newNode->notaN2P = notaN2P;
    newNode->notaN1S = notaN1S;
    newNode->notaN2S = notaN2S;
    newNode->next = nullptr;

    // Adicionar o novo nó à lista encadeada
    if (head == nullptr) {
        head = newNode;
    } else {
        Student* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Exibir mensagem de sucesso ao cadastrar o aluno
    QMessageBox::information(this, "Sucesso", "Aluno cadastrado com sucesso!");

    // Limpar os campos de entrada de texto após o cadastro
    ui->lineEditUsername->clear();
    ui->lineEdit_n1First->clear();
    ui->lineEdit_n2First->clear();
    ui->lineEdit_n1Second->clear();
    ui->lineEdit_n2Second->clear();
    ui->comboBoxDiscipline->setCurrentIndex(0);  // Opcional: redefinir a seleção da disciplina para o primeiro item
}




void MainWindow::on_pushButtonPrint_clicked() {
    QFileDialog fileDialog(this, "Salvar arquivo CSV", "", "CSV files (*.csv)");
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    if (fileDialog.exec() == QDialog::Accepted) {
        QString filePath = fileDialog.selectedFiles().first();
        // Cria o arquivo para escrever
        QFile file(filePath);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            QMessageBox::warning(this, "Erro", "Não foi possível criar o arquivo CSV");
            return;
        }

        // Cria o stream de texto para escrever no arquivo
        QTextStream stream(&file);

        // Cabeçalho do CSV
        stream << "Nome do Aluno" << "," << "Disciplina" << "," << "N1 1 Bimestre" << ","
               << "N2 1 Bimestre" << "," << "Media 1 Bimestre" << ","
               << "N1 2 Bimestre" << "," << "N2 2 Bimestre" << ","
               << "Media 2 Bimestre" << "," << "Media Semestral" << "," << "Situação" << "\n";

        // Itera sobre a lista de estudantes
        Student* current = head;
        while (current != nullptr) {
            // Calcula a média do 1º e 2º bimestre
            float mediaP = (current->notaN1P + current->notaN2P) / 2;
            float mediaS = (current->notaN1S + current->notaN2S) / 2;
            float mediaFinal = (mediaP + mediaS) / 2;

            // Verifica se o aluno fez a prova substitutiva
            if (current->notaSubstitutiva != 0) {
                // Substitui a menor nota do primeiro bimestre
                if (current->notaN1P < current->notaN2P) {
                    current->notaN1P = current->notaSubstitutiva;
                } else {
                    current->notaN2P = current->notaSubstitutiva;
                }
                // Recalcula a média do 1º bimestre e a média final
                mediaP = (current->notaN1P + current->notaN2P) / 2;
                mediaFinal = (mediaP + mediaS) / 2;
            }

            // Determina a situação do aluno
            QString situacao = (mediaFinal >= 6) ? "Aprovado" : "Reprovado";

            // Escreve a linha do aluno no arquivo CSV
            stream << current->nomeAluno << "," << current->nomeDisciplina << ","
                   << current->notaN1P << "," << current->notaN2P << "," << mediaP << ","
                   << current->notaN1S << "," << current->notaN2S << "," << mediaS << ","
                   << mediaFinal << "," << situacao << "\n";

            // Vai para o próximo aluno
            current = current->next;
        }

        // Fecha o arquivo
        file.close();
    }
}


void MainWindow::on_pushButtonCheckTest_2_clicked()
{
    // Obter os valores de entrada do segundo semestre
    float notaN1S = ui->lineEdit_n1Second->text().toFloat();
    float notaN2S = ui->lineEdit_n2Second->text().toFloat();

    // Calcular a média do segundo semestre
    float mediaS = (notaN1S + notaN2S) / 2;

    // Verificar se a média do segundo semestre está entre 2 e 6
    if (mediaS >= 2 && mediaS < 6) {
        QDialog dialog(this);
        dialog.setWindowTitle("Nota da Substitutiva - Segundo Semestre");

        // Criar um QLineEdit para a nota substitutiva
        QLineEdit *lineEditNotaSubstitutiva = new QLineEdit(&dialog);
        lineEditNotaSubstitutiva->setPlaceholderText("Insira a nota da substitutiva");

        // Criar um layout para o diálogo
        QVBoxLayout *layout = new QVBoxLayout;
        layout->addWidget(lineEditNotaSubstitutiva);

        // Adicionar botões Ok e Cancelar
        QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
        layout->addWidget(buttonBox);

        // Conectar os sinais dos botões Ok e Cancelar
        connect(buttonBox, &QDialogButtonBox::accepted, &dialog, &QDialog::accept);
        connect(buttonBox, &QDialogButtonBox::rejected, &dialog, &QDialog::reject);

        // Definir o layout do diálogo
        dialog.setLayout(layout);

        // Executar o diálogo e pegar a nota da substitutiva
        if (dialog.exec() == QDialog::Accepted) {
            float notaSubstitutiva = lineEditNotaSubstitutiva->text().toFloat();

            // Verificar se a nota substitutiva é válida
            if (notaSubstitutiva > 10 || notaSubstitutiva < 0) {
                QMessageBox::warning(this, "Erro", "Impossível calcular substitutiva, digite um número válido entre 0 e 10.");
                return;
            }

            // Substituir a menor nota (entre N1S e N2S) pela nota substitutiva se ela for maior
            if (notaSubstitutiva > notaN1S && notaN1S <= notaN2S) {
                // Substitui notaN1S pela substitutiva e atualiza o input
                notaN1S = notaSubstitutiva;
                ui->lineEdit_n1Second->setText(QString::number(notaN1S));
            } else if (notaSubstitutiva > notaN2S && notaN2S <= notaN1S) {
                // Substitui notaN2S pela substitutiva e atualiza o input
                notaN2S = notaSubstitutiva;
                ui->lineEdit_n2Second->setText(QString::number(notaN2S));
            }

            // Recalcular a média após a substituição
            mediaS = (notaN1S + notaN2S) / 2;

            // Exibir a nova média do segundo semestre
            QString resultado = QString("Nova média do Segundo Semestre: %1").arg(mediaS);
            QMessageBox::information(this, "Resultado", resultado);
        }
    } else {
        // Exibir mensagem de erro se a média do segundo semestre não estiver dentro das regras
        QMessageBox::warning(this, "Erro", "Impossível calcular substitutiva. Sua média do segundo semestre não se encaixa nas regras (entre 2 e 6).");
    }
}



