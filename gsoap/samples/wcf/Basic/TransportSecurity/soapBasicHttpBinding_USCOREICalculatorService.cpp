/* soapBasicHttpBinding_USCOREICalculatorService.cpp
   Generated by gSOAP 2.8.48 for calculator.h

gSOAP XML Web services tools
Copyright (C) 2000-2017, Robert van Engelen, Genivia Inc. All Rights Reserved.
The soapcpp2 tool and its generated software are released under the GPL.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
--------------------------------------------------------------------------------
A commercial use license is available from Genivia Inc., contact@genivia.com
--------------------------------------------------------------------------------
*/

#include "soapBasicHttpBinding_USCOREICalculatorService.h"

BasicHttpBinding_USCOREICalculatorService::BasicHttpBinding_USCOREICalculatorService()
{	this->soap = soap_new();
	this->soap_own = true;
	BasicHttpBinding_USCOREICalculatorService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

BasicHttpBinding_USCOREICalculatorService::BasicHttpBinding_USCOREICalculatorService(const BasicHttpBinding_USCOREICalculatorService& rhs)
{	this->soap = rhs.soap;
	this->soap_own = false;
}

BasicHttpBinding_USCOREICalculatorService::BasicHttpBinding_USCOREICalculatorService(struct soap *_soap)
{	this->soap = _soap;
	this->soap_own = false;
	BasicHttpBinding_USCOREICalculatorService_init(_soap->imode, _soap->omode);
}

BasicHttpBinding_USCOREICalculatorService::BasicHttpBinding_USCOREICalculatorService(soap_mode iomode)
{	this->soap = soap_new();
	this->soap_own = true;
	BasicHttpBinding_USCOREICalculatorService_init(iomode, iomode);
}

BasicHttpBinding_USCOREICalculatorService::BasicHttpBinding_USCOREICalculatorService(soap_mode imode, soap_mode omode)
{	this->soap = soap_new();
	this->soap_own = true;
	BasicHttpBinding_USCOREICalculatorService_init(imode, omode);
}

BasicHttpBinding_USCOREICalculatorService::~BasicHttpBinding_USCOREICalculatorService()
{	if (this->soap_own)
		soap_free(this->soap);
}

void BasicHttpBinding_USCOREICalculatorService::BasicHttpBinding_USCOREICalculatorService_init(soap_mode imode, soap_mode omode)
{	soap_imode(this->soap, imode);
	soap_omode(this->soap, omode);
	static const struct Namespace namespaces[] = {
        {"SOAP-ENV", "http://schemas.xmlsoap.org/soap/envelope/", "http://www.w3.org/*/soap-envelope", NULL},
        {"SOAP-ENC", "http://schemas.xmlsoap.org/soap/encoding/", "http://www.w3.org/*/soap-encoding", NULL},
        {"xsi", "http://www.w3.org/2001/XMLSchema-instance", "http://www.w3.org/*/XMLSchema-instance", NULL},
        {"xsd", "http://www.w3.org/2001/XMLSchema", "http://www.w3.org/*/XMLSchema", NULL},
        {"tempuri", "http://tempuri.org/", NULL, NULL},
        {"mssamt", "http://Microsoft.Samples.TransportSecurity", NULL, NULL},
        {NULL, NULL, NULL, NULL}
    };
	soap_set_namespaces(this->soap, namespaces);
}

void BasicHttpBinding_USCOREICalculatorService::destroy()
{	soap_destroy(this->soap);
	soap_end(this->soap);
}

void BasicHttpBinding_USCOREICalculatorService::reset()
{	this->destroy();
	soap_done(this->soap);
	soap_initialize(this->soap);
	BasicHttpBinding_USCOREICalculatorService_init(SOAP_IO_DEFAULT, SOAP_IO_DEFAULT);
}

#ifndef WITH_PURE_VIRTUAL
BasicHttpBinding_USCOREICalculatorService *BasicHttpBinding_USCOREICalculatorService::copy()
{	BasicHttpBinding_USCOREICalculatorService *dup = SOAP_NEW_COPY(BasicHttpBinding_USCOREICalculatorService);
	if (dup)
		soap_copy_context(dup->soap, this->soap);
	return dup;
}
#endif

BasicHttpBinding_USCOREICalculatorService& BasicHttpBinding_USCOREICalculatorService::operator=(const BasicHttpBinding_USCOREICalculatorService& rhs)
{	if (this->soap_own)
		soap_free(this->soap);
	this->soap = rhs.soap;
	this->soap_own = false;
	return *this;
}

int BasicHttpBinding_USCOREICalculatorService::soap_close_socket()
{	return soap_closesock(this->soap);
}

int BasicHttpBinding_USCOREICalculatorService::soap_force_close_socket()
{	return soap_force_closesock(this->soap);
}

int BasicHttpBinding_USCOREICalculatorService::soap_senderfault(const char *string, const char *detailXML)
{	return ::soap_sender_fault(this->soap, string, detailXML);
}

int BasicHttpBinding_USCOREICalculatorService::soap_senderfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_sender_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

int BasicHttpBinding_USCOREICalculatorService::soap_receiverfault(const char *string, const char *detailXML)
{	return ::soap_receiver_fault(this->soap, string, detailXML);
}

int BasicHttpBinding_USCOREICalculatorService::soap_receiverfault(const char *subcodeQName, const char *string, const char *detailXML)
{	return ::soap_receiver_fault_subcode(this->soap, subcodeQName, string, detailXML);
}

void BasicHttpBinding_USCOREICalculatorService::soap_print_fault(FILE *fd)
{	::soap_print_fault(this->soap, fd);
}

#ifndef WITH_LEAN
#ifndef WITH_COMPAT
void BasicHttpBinding_USCOREICalculatorService::soap_stream_fault(std::ostream& os)
{	::soap_stream_fault(this->soap, os);
}
#endif

char *BasicHttpBinding_USCOREICalculatorService::soap_sprint_fault(char *buf, size_t len)
{	return ::soap_sprint_fault(this->soap, buf, len);
}
#endif

void BasicHttpBinding_USCOREICalculatorService::soap_noheader()
{	this->soap->header = NULL;
}

::SOAP_ENV__Header *BasicHttpBinding_USCOREICalculatorService::soap_header()
{	return this->soap->header;
}

#ifndef WITH_NOIO
int BasicHttpBinding_USCOREICalculatorService::run(int port)
{	if (!soap_valid_socket(this->soap->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->soap->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->soap->errnum == 0) // timeout?
				this->soap->error = SOAP_OK;
			break;
		}
		if (this->serve())
			break;
		this->destroy();
	}
	return this->soap->error;
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int BasicHttpBinding_USCOREICalculatorService::ssl_run(int port)
{	if (!soap_valid_socket(this->soap->master) && !soap_valid_socket(this->bind(NULL, port, 100)))
		return this->soap->error;
	for (;;)
	{	if (!soap_valid_socket(this->accept()))
		{	if (this->soap->errnum == 0) // timeout?
				this->soap->error = SOAP_OK;
			break;
		}
		if (this->ssl_accept() || this->serve())
			break;
		this->destroy();
	}
	return this->soap->error;
}
#endif

SOAP_SOCKET BasicHttpBinding_USCOREICalculatorService::bind(const char *host, int port, int backlog)
{	return soap_bind(this->soap, host, port, backlog);
}

SOAP_SOCKET BasicHttpBinding_USCOREICalculatorService::accept()
{	return soap_accept(this->soap);
}

#if defined(WITH_OPENSSL) || defined(WITH_GNUTLS)
int BasicHttpBinding_USCOREICalculatorService::ssl_accept()
{	return soap_ssl_accept(this->soap);
}
#endif
#endif

int BasicHttpBinding_USCOREICalculatorService::serve()
{
#ifndef WITH_FASTCGI
	this->soap->keep_alive = this->soap->max_keep_alive + 1;
#endif
	do
	{
#ifndef WITH_FASTCGI
		if (this->soap->keep_alive > 0 && this->soap->max_keep_alive > 0)
			this->soap->keep_alive--;
#endif
		if (soap_begin_serve(this->soap))
		{	if (this->soap->error >= SOAP_STOP)
				continue;
			return this->soap->error;
		}
		if ((dispatch() || (this->soap->fserveloop && this->soap->fserveloop(this->soap))) && this->soap->error && this->soap->error < SOAP_STOP)
		{
#ifdef WITH_FASTCGI
			soap_send_fault(this->soap);
#else
			return soap_send_fault(this->soap);
#endif
		}
#ifdef WITH_FASTCGI
		soap_destroy(this->soap);
		soap_end(this->soap);
	} while (1);
#else
	} while (this->soap->keep_alive);
#endif
	return SOAP_OK;
}

static int serve___tempuri__Add(struct soap*, BasicHttpBinding_USCOREICalculatorService*);
static int serve___tempuri__Subtract(struct soap*, BasicHttpBinding_USCOREICalculatorService*);
static int serve___tempuri__Multiply(struct soap*, BasicHttpBinding_USCOREICalculatorService*);
static int serve___tempuri__Divide(struct soap*, BasicHttpBinding_USCOREICalculatorService*);

int BasicHttpBinding_USCOREICalculatorService::dispatch()
{	return dispatch(this->soap);
}

int BasicHttpBinding_USCOREICalculatorService::dispatch(struct soap* soap)
{
	BasicHttpBinding_USCOREICalculatorService_init(soap->imode, soap->omode);

	soap_peek_element(soap);
	if ((!soap->action && !soap_match_tag(soap, soap->tag, "mssamt:Add")) || (soap->action && !strcmp(soap->action, "http://Microsoft.Samples.TransportSecurity/ICalculator/Add")))
		return serve___tempuri__Add(soap, this);
	if ((!soap->action && !soap_match_tag(soap, soap->tag, "mssamt:Subtract")) || (soap->action && !strcmp(soap->action, "http://Microsoft.Samples.TransportSecurity/ICalculator/Subtract")))
		return serve___tempuri__Subtract(soap, this);
	if ((!soap->action && !soap_match_tag(soap, soap->tag, "mssamt:Multiply")) || (soap->action && !strcmp(soap->action, "http://Microsoft.Samples.TransportSecurity/ICalculator/Multiply")))
		return serve___tempuri__Multiply(soap, this);
	if ((!soap->action && !soap_match_tag(soap, soap->tag, "mssamt:Divide")) || (soap->action && !strcmp(soap->action, "http://Microsoft.Samples.TransportSecurity/ICalculator/Divide")))
		return serve___tempuri__Divide(soap, this);
	return soap->error = SOAP_NO_METHOD;
}

static int serve___tempuri__Add(struct soap *soap, BasicHttpBinding_USCOREICalculatorService *service)
{	struct __tempuri__Add soap_tmp___tempuri__Add;
	_mssamt__AddResponse mssamt__AddResponse;
	mssamt__AddResponse.soap_default(soap);
	soap_default___tempuri__Add(soap, &soap_tmp___tempuri__Add);
	if (!soap_get___tempuri__Add(soap, &soap_tmp___tempuri__Add, "-tempuri:Add", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->Add(soap_tmp___tempuri__Add.mssamt__Add, &mssamt__AddResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	mssamt__AddResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || mssamt__AddResponse.soap_put(soap, "mssamt:AddResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || mssamt__AddResponse.soap_put(soap, "mssamt:AddResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__Subtract(struct soap *soap, BasicHttpBinding_USCOREICalculatorService *service)
{	struct __tempuri__Subtract soap_tmp___tempuri__Subtract;
	_mssamt__SubtractResponse mssamt__SubtractResponse;
	mssamt__SubtractResponse.soap_default(soap);
	soap_default___tempuri__Subtract(soap, &soap_tmp___tempuri__Subtract);
	if (!soap_get___tempuri__Subtract(soap, &soap_tmp___tempuri__Subtract, "-tempuri:Subtract", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->Subtract(soap_tmp___tempuri__Subtract.mssamt__Subtract, &mssamt__SubtractResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	mssamt__SubtractResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || mssamt__SubtractResponse.soap_put(soap, "mssamt:SubtractResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || mssamt__SubtractResponse.soap_put(soap, "mssamt:SubtractResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__Multiply(struct soap *soap, BasicHttpBinding_USCOREICalculatorService *service)
{	struct __tempuri__Multiply soap_tmp___tempuri__Multiply;
	_mssamt__MultiplyResponse mssamt__MultiplyResponse;
	mssamt__MultiplyResponse.soap_default(soap);
	soap_default___tempuri__Multiply(soap, &soap_tmp___tempuri__Multiply);
	if (!soap_get___tempuri__Multiply(soap, &soap_tmp___tempuri__Multiply, "-tempuri:Multiply", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->Multiply(soap_tmp___tempuri__Multiply.mssamt__Multiply, &mssamt__MultiplyResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	mssamt__MultiplyResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || mssamt__MultiplyResponse.soap_put(soap, "mssamt:MultiplyResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || mssamt__MultiplyResponse.soap_put(soap, "mssamt:MultiplyResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

static int serve___tempuri__Divide(struct soap *soap, BasicHttpBinding_USCOREICalculatorService *service)
{	struct __tempuri__Divide soap_tmp___tempuri__Divide;
	_mssamt__DivideResponse mssamt__DivideResponse;
	mssamt__DivideResponse.soap_default(soap);
	soap_default___tempuri__Divide(soap, &soap_tmp___tempuri__Divide);
	if (!soap_get___tempuri__Divide(soap, &soap_tmp___tempuri__Divide, "-tempuri:Divide", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = service->Divide(soap_tmp___tempuri__Divide.mssamt__Divide, &mssamt__DivideResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	mssamt__DivideResponse.soap_serialize(soap);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || mssamt__DivideResponse.soap_put(soap, "mssamt:DivideResponse", "")
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || mssamt__DivideResponse.soap_put(soap, "mssamt:DivideResponse", "")
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}
/* End of server object code */
