#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "inmigrante.h"


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_start_clicked();

    void on_boton_aceptar_clicked();
    void on_boton_denegar_clicked();

    void on_boton_reiniciar_clicked();

private:
    Ui::MainWindow *ui;
    std::vector<Inmigrante> inmigrantes;
    int indiceActual;
    int aceptados;
    int denegados;
    int nivelActual;

    void cargarReglas(int nivel);
    void mostrarResultadoFinal();
    void cargarNivel(int nivel);
};
#endif // MAINWINDOW_H
