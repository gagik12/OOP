#pragma once

enum class Protocol
{
    HTTP = 80,
    HTTPS = 443
};

class CHttpUrl
{
public:
    CHttpUrl(std::string const& url);
    CHttpUrl(
        std::string const& domain,
        std::string const& document,
        Protocol protocol = Protocol::HTTP,
        unsigned short port = static_cast< unsigned short>(Protocol::HTTP)
    );

    std::string GetUrl() const;
    Protocol GetProtocol() const;
    std::string GetDomain() const;
    unsigned short GetPort() const;
    std::string GetDocument() const;
private:
    std::string m_document;
    std::string m_domain;
    unsigned short m_port;
    Protocol m_protocol;

    Protocol ToProtocolType(std::string const& protocol) const;
    Protocol ParseProtocol(std::string & urlRef) const;

    void ValidateDomain(std::string const& domain) const;
    std::string ParseDomain(std::string & urlRef) const;

    std::string ToStringPort() const;
    std::string ToStringProtocol() const;
    unsigned short ParsePort(std::string & urlRef) const;

    void ValidateDocument(std::string const& document) const;
};
