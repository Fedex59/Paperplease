#ifndef DOCUMENTO_H
#define DOCUMENTO_H

#include <string>
#include <ctime>

class Documento
{
public:
    Documento(const std::string& numero, const std::tm& fechaExpiracion);
    virtual ~Documento() = default;

    virtual std::string tipo() const = 0;
    virtual bool esValido() const;
    virtual std::string obtenerInformacion() const = 0;

protected:
    std::string m_numero;
    std::tm m_fechaExpiracion;
};

class Pasaporte : public Documento
{
public:
    Pasaporte(const std::string& numero, const std::tm& fechaExpiracion);

    std::string tipo() const override;
    std::string obtenerInformacion() const override;
};

class Visa : public Documento
{
public:
    Visa(const std::string& numero, const std::tm& fechaExpiracion, const std::string& tipoVisa);

    std::string tipo() const override;
    std::string obtenerInformacion() const override;

private:
    std::string m_tipoVisa;
};

#endif // DOCUMENTO_H
