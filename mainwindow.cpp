#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "inmigrante.h"
#include "archivo.h"
#include <vector>
#include <string>
#include <QString>
#include <QMessageBox>
#include "inmigrante.h"  // Asegúrate de incluir el encabezado correcto

using namespace std;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , indiceActual(0) // Inicializar el índice actual a 0
    , aceptados(0) // Inicializar el contador de aceptados a 0
    , denegados(0) // Inicializar el contador de denegados a 0
    , nivelActual(1) // Inicializar el nivel actual a 1
{
    ui->setupUi(this);

    // Deshabilitar los botones "Aceptar" y "Denegar" inicialmente
    ui->boton_aceptar->setEnabled(false);
    ui->boton_denegar->setEnabled(false);
    // Mostrar el nivel actual en el QLabel
    ui->nivel_valor->setText(QString::number(nivelActual));
    ui->boton_start->setEnabled(true);
    ui->boton_reiniciar->setEnabled(true);

    connect(ui->boton_start, &QPushButton::clicked, this, &MainWindow::on_start_clicked);
    connect(ui->boton_reiniciar, &QPushButton::clicked, this, &MainWindow::on_boton_reiniciar_clicked);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_start_clicked()
{
    // Cargar el nivel actual
    cargarNivel(nivelActual);
}

void MainWindow::cargarNivel(int nivel)
{
    Archivo arch;

    // Leer el archivo correspondiente al nivel actual
    QString archivoPath = QString("niveles/%1/inmi.txt").arg(nivel);

    std::vector<std::string> listado = arch.leer(archivoPath.toStdString());

    // Parsear la lista de inmigrantes
    inmigrantes = parsearInmigrantes(listado);

    // Leer y mostrar las reglas del juego
    cargarReglas(nivel);

    // Reiniciar el índice actual y los contadores
    indiceActual = 0;
    aceptados = 0;
    denegados = 0;

    // Habilitar los botones "Aceptar" y "Denegar"
    ui->boton_aceptar->setEnabled(true);
    ui->boton_denegar->setEnabled(true);

    // Mostrar información del primer inmigrante en el QPlainTextEdit
    if (!inmigrantes.empty()) {
        QString info = QString::fromStdString(inmigrantes[indiceActual].obtenerInformacion());
        ui->datoInmigrante->setPlainText(info);
    } else {
        ui->datoInmigrante->setPlainText("No hay inmigrantes para mostrar.");
    }
}

void MainWindow::on_boton_aceptar_clicked()
{
    // Incrementar el contador de aceptados
    ++aceptados;

    // Incrementar el índice actual
    ++indiceActual;

    // Verificar si hay más inmigrantes para mostrar
    if (indiceActual < inmigrantes.size()) {
        QString info = QString::fromStdString(inmigrantes[indiceActual].obtenerInformacion());
        ui->datoInmigrante->setPlainText(info);
    } else {
        mostrarResultadoFinal();
    }
}

void MainWindow::on_boton_denegar_clicked()
{
    // Incrementar el contador de denegados
    ++denegados;

    // Incrementar el índice actual
    ++indiceActual;

    // Verificar si hay más inmigrantes para mostrar
    if (indiceActual < inmigrantes.size()) {
        QString info = QString::fromStdString(inmigrantes[indiceActual].obtenerInformacion());
        ui->datoInmigrante->setPlainText(info);
    } else {
        mostrarResultadoFinal();
    }
}

// Mostrar un cuadro de diálogo con el resultado final

void MainWindow::mostrarResultadoFinal()
{
    // Deshabilitar los botones "Aceptar" y "Denegar"
    ui->boton_aceptar->setEnabled(false);
    ui->boton_denegar->setEnabled(false);

    // Mostrar el resultado final en el QPlainTextEdit
    ui->datoInmigrante->setPlainText(QString("No hay más inmigrantes para mostrar.\nAceptados: %1\nDenegados: %2")
                                         .arg(aceptados)
                                         .arg(denegados));

    // Mostrar un cuadro de diálogo con el resultado final
    QMessageBox msgBox;
    msgBox.setText(QString("Nivel %1 completado.\nAceptados: %2\nDenegados: %3\n").arg(nivelActual).arg(aceptados).arg(denegados));
    msgBox.setInformativeText("¿Deseas pasar al siguiente nivel?");
    QPushButton *noButton = msgBox.addButton(tr("No"), QMessageBox::NoRole);
    QPushButton *yesButton = msgBox.addButton(tr("Sí"), QMessageBox::YesRole);
    msgBox.setDefaultButton(yesButton);
    msgBox.exec();

    if (msgBox.clickedButton() == yesButton) {
        // Incrementar el nivel y cargar el siguiente
        ++nivelActual;
        ui->nivel_valor->setText(QString::number(nivelActual));
        cargarNivel(nivelActual);
    }
}

void MainWindow::cargarReglas(int nivel)
{
    Archivo arch;

    // Leer el archivo de reglas dependiendo el nivel
    QString archivoPath = QString("niveles/%1/reglas.txt").arg(nivel);
    std::vector<std::string> reglasListado = arch.leer(archivoPath.toStdString());

    // Convertir el contenido del archivo a un QString
    QString reglasTexto;
    for (const auto& linea : reglasListado) {
        reglasTexto += QString::fromStdString(linea) + "\n";
    }

    // Mostrar el contenido en el QPlainTextEdit
    ui->reglas->setPlainText(reglasTexto);
}



void MainWindow::on_boton_reiniciar_clicked()
{
    // Reiniciar todos los valores y la interfaz de usuario
    indiceActual = 0;
    aceptados = 0;
    denegados = 0;
    nivelActual = 1; // Reiniciar el nivel a 1

    // Reiniciar la interfaz de usuario
    ui->nivel_valor->setText(QString::number(nivelActual));
    ui->datoInmigrante->clear();
    ui->reglas->clear();

    // Deshabilitar los botones "Aceptar" y "Denegar"
    ui->boton_aceptar->setEnabled(false);
    ui->boton_denegar->setEnabled(false);

    // Habilitar el botón "Start" y deshabilitar el botón "Reiniciar"
    ui->boton_start->setEnabled(true);
    ui->boton_reiniciar->setEnabled(true);

    // Mostrar un mensaje de confirmación
    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText("Datos restablecidos correctamente.");
    msgBox.setWindowTitle("Reinicio Completo");
    msgBox.exec();
}
