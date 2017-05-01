/* soapStub.h
   Generated by gSOAP 2.8.11 from quote.h

Copyright(C) 2000-2012, Robert van Engelen, Genivia Inc. All Rights Reserved.
The generated code is released under one of the following licenses:
1) GPL or 2) Genivia's license for commercial use.
This program is released under the GPL with the additional exemption that
compiling, linking, and/or using OpenSSL is allowed.
*/

#ifndef soapStub_H
#define soapStub_H
#include <vector>
#define SOAP_NAMESPACE_OF_ns1	"http://ws.cdyne.com/"
#include "stdsoap2.h"
#if GSOAP_VERSION != 20811
# error "GSOAP VERSION MISMATCH IN GENERATED CODE: PLEASE REINSTALL PACKAGE"
#endif


/******************************************************************************\
 *                                                                            *
 * Enumerations                                                               *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Types with Custom Serializers                                              *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Classes and Structs                                                        *
 *                                                                            *
\******************************************************************************/


#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#if 0 /* volatile type: do not declare here, declared elsewhere */

#endif

#ifndef SOAP_TYPE_ns1__QuoteData
#define SOAP_TYPE_ns1__QuoteData (11)
/* ns1:QuoteData */
class SOAP_CMAC ns1__QuoteData
{
public:
	std::string *StockSymbol;	/* optional element of type xsd:string */
	std::string LastTradeAmount;	/* required element of type xsd:decimal */
	time_t LastTradeDateTime;	/* required element of type xsd:dateTime */
	std::string StockChange;	/* required element of type xsd:decimal */
	std::string OpenAmount;	/* required element of type xsd:decimal */
	std::string DayHigh;	/* required element of type xsd:decimal */
	std::string DayLow;	/* required element of type xsd:decimal */
	int StockVolume;	/* required element of type xsd:int */
	std::string PrevCls;	/* required element of type xsd:decimal */
	std::string *ChangePercent;	/* optional element of type xsd:string */
	std::string *FiftyTwoWeekRange;	/* optional element of type xsd:string */
	std::string EarnPerShare;	/* required element of type xsd:decimal */
	std::string PE;	/* required element of type xsd:decimal */
	std::string *CompanyName;	/* optional element of type xsd:string */
	bool QuoteError;	/* required element of type xsd:boolean */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 11; } /* = unique id SOAP_TYPE_ns1__QuoteData */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         ns1__QuoteData() { ns1__QuoteData::soap_default(NULL); }
	virtual ~ns1__QuoteData() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetQuote
#define SOAP_TYPE__ns1__GetQuote (12)
/* ns1:GetQuote */
class SOAP_CMAC _ns1__GetQuote
{
public:
	std::string *StockSymbol;	/* optional element of type xsd:string */
	std::string *LicenseKey;	/* optional element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 12; } /* = unique id SOAP_TYPE__ns1__GetQuote */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetQuote() { _ns1__GetQuote::soap_default(NULL); }
	virtual ~_ns1__GetQuote() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetQuoteResponse
#define SOAP_TYPE__ns1__GetQuoteResponse (13)
/* ns1:GetQuoteResponse */
class SOAP_CMAC _ns1__GetQuoteResponse
{
public:
	ns1__QuoteData *GetQuoteResult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type ns1:QuoteData */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 13; } /* = unique id SOAP_TYPE__ns1__GetQuoteResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetQuoteResponse() { _ns1__GetQuoteResponse::soap_default(NULL); }
	virtual ~_ns1__GetQuoteResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetQuickQuote
#define SOAP_TYPE__ns1__GetQuickQuote (14)
/* ns1:GetQuickQuote */
class SOAP_CMAC _ns1__GetQuickQuote
{
public:
	std::string *StockSymbol;	/* optional element of type xsd:string */
	std::string *LicenseKey;	/* optional element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 14; } /* = unique id SOAP_TYPE__ns1__GetQuickQuote */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetQuickQuote() { _ns1__GetQuickQuote::soap_default(NULL); }
	virtual ~_ns1__GetQuickQuote() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetQuickQuoteResponse
#define SOAP_TYPE__ns1__GetQuickQuoteResponse (15)
/* ns1:GetQuickQuoteResponse */
class SOAP_CMAC _ns1__GetQuickQuoteResponse
{
public:
	std::string GetQuickQuoteResult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* required element of type xsd:decimal */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 15; } /* = unique id SOAP_TYPE__ns1__GetQuickQuoteResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetQuickQuoteResponse() { _ns1__GetQuickQuoteResponse::soap_default(NULL); }
	virtual ~_ns1__GetQuickQuoteResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetQuoteDataSet
#define SOAP_TYPE__ns1__GetQuoteDataSet (16)
/* ns1:GetQuoteDataSet */
class SOAP_CMAC _ns1__GetQuoteDataSet
{
public:
	std::string *StockSymbols;	/* optional element of type xsd:string */
	std::string *LicenseKey;	/* optional element of type xsd:string */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 16; } /* = unique id SOAP_TYPE__ns1__GetQuoteDataSet */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetQuoteDataSet() { _ns1__GetQuoteDataSet::soap_default(NULL); }
	virtual ~_ns1__GetQuoteDataSet() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult
#define SOAP_TYPE__ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult (24)
/* ns1:GetQuoteDataSetResponse-GetQuoteDataSetResult */
class SOAP_CMAC _ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult
{
public:
	char *xsd__schema;	/* required element of type xsd:schema */
	char *__any;
public:
	virtual int soap_type() const { return 24; } /* = unique id SOAP_TYPE__ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult() { _ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult::soap_default(NULL); }
	virtual ~_ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult() { }
};
#endif

#ifndef SOAP_TYPE__ns1__GetQuoteDataSetResponse
#define SOAP_TYPE__ns1__GetQuoteDataSetResponse (17)
/* ns1:GetQuoteDataSetResponse */
class SOAP_CMAC _ns1__GetQuoteDataSetResponse
{
public:
	_ns1__GetQuoteDataSetResponse_GetQuoteDataSetResult *GetQuoteDataSetResult;	/* SOAP 1.2 RPC return element (when namespace qualified) */	/* optional element of type ns1:GetQuoteDataSetResponse-GetQuoteDataSetResult */
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 17; } /* = unique id SOAP_TYPE__ns1__GetQuoteDataSetResponse */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__GetQuoteDataSetResponse() { _ns1__GetQuoteDataSetResponse::soap_default(NULL); }
	virtual ~_ns1__GetQuoteDataSetResponse() { }
};
#endif

#ifndef SOAP_TYPE__ns1__DataSet
#define SOAP_TYPE__ns1__DataSet (18)
/* ns1:DataSet */
class SOAP_CMAC _ns1__DataSet
{
public:
	char *xsd__schema;	/* required element of type xsd:schema */
	char *__any;
	struct soap *soap;	/* transient */
public:
	virtual int soap_type() const { return 18; } /* = unique id SOAP_TYPE__ns1__DataSet */
	virtual void soap_default(struct soap*);
	virtual void soap_serialize(struct soap*) const;
	virtual int soap_put(struct soap*, const char*, const char*) const;
	virtual int soap_out(struct soap*, const char*, int, const char*) const;
	virtual void *soap_get(struct soap*, const char*, const char*);
	virtual void *soap_in(struct soap*, const char*, const char*);
	         _ns1__DataSet() { _ns1__DataSet::soap_default(NULL); }
	virtual ~_ns1__DataSet() { }
};
#endif

#ifndef SOAP_TYPE___ns1__GetQuote
#define SOAP_TYPE___ns1__GetQuote (29)
/* Operation wrapper: */
struct __ns1__GetQuote
{
public:
	_ns1__GetQuote *ns1__GetQuote;	/* optional element of type ns1:GetQuote */
};
#endif

#ifndef SOAP_TYPE___ns1__GetQuickQuote
#define SOAP_TYPE___ns1__GetQuickQuote (33)
/* Operation wrapper: */
struct __ns1__GetQuickQuote
{
public:
	_ns1__GetQuickQuote *ns1__GetQuickQuote;	/* optional element of type ns1:GetQuickQuote */
};
#endif

#ifndef SOAP_TYPE___ns1__GetQuoteDataSet
#define SOAP_TYPE___ns1__GetQuoteDataSet (37)
/* Operation wrapper: */
struct __ns1__GetQuoteDataSet
{
public:
	_ns1__GetQuoteDataSet *ns1__GetQuoteDataSet;	/* optional element of type ns1:GetQuoteDataSet */
};
#endif

#ifndef SOAP_TYPE___ns1__GetQuote_
#define SOAP_TYPE___ns1__GetQuote_ (39)
/* Operation wrapper: */
struct __ns1__GetQuote_
{
public:
	_ns1__GetQuote *ns1__GetQuote;	/* optional element of type ns1:GetQuote */
};
#endif

#ifndef SOAP_TYPE___ns1__GetQuickQuote_
#define SOAP_TYPE___ns1__GetQuickQuote_ (41)
/* Operation wrapper: */
struct __ns1__GetQuickQuote_
{
public:
	_ns1__GetQuickQuote *ns1__GetQuickQuote;	/* optional element of type ns1:GetQuickQuote */
};
#endif

#ifndef SOAP_TYPE___ns1__GetQuoteDataSet_
#define SOAP_TYPE___ns1__GetQuoteDataSet_ (43)
/* Operation wrapper: */
struct __ns1__GetQuoteDataSet_
{
public:
	_ns1__GetQuoteDataSet *ns1__GetQuoteDataSet;	/* optional element of type ns1:GetQuoteDataSet */
};
#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Header
#define SOAP_TYPE_SOAP_ENV__Header (44)
/* SOAP Header: */
struct SOAP_ENV__Header
{
#ifdef WITH_NOEMPTYSTRUCT
private:
	char dummy;	/* dummy member to enable compilation */
#endif
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Code
#define SOAP_TYPE_SOAP_ENV__Code (45)
/* SOAP Fault Code: */
struct SOAP_ENV__Code
{
public:
	char *SOAP_ENV__Value;	/* optional element of type xsd:QName */
	struct SOAP_ENV__Code *SOAP_ENV__Subcode;	/* optional element of type SOAP-ENV:Code */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Detail
#define SOAP_TYPE_SOAP_ENV__Detail (47)
/* SOAP-ENV:Detail */
struct SOAP_ENV__Detail
{
public:
	char *__any;
	int __type;	/* any type of element <fault> (defined below) */
	void *fault;	/* transient */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Reason
#define SOAP_TYPE_SOAP_ENV__Reason (50)
/* SOAP-ENV:Reason */
struct SOAP_ENV__Reason
{
public:
	char *SOAP_ENV__Text;	/* optional element of type xsd:string */
};
#endif

#endif

#ifndef WITH_NOGLOBAL

#ifndef SOAP_TYPE_SOAP_ENV__Fault
#define SOAP_TYPE_SOAP_ENV__Fault (51)
/* SOAP Fault: */
struct SOAP_ENV__Fault
{
public:
	char *faultcode;	/* optional element of type xsd:QName */
	char *faultstring;	/* optional element of type xsd:string */
	char *faultactor;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *detail;	/* optional element of type SOAP-ENV:Detail */
	struct SOAP_ENV__Code *SOAP_ENV__Code;	/* optional element of type SOAP-ENV:Code */
	struct SOAP_ENV__Reason *SOAP_ENV__Reason;	/* optional element of type SOAP-ENV:Reason */
	char *SOAP_ENV__Node;	/* optional element of type xsd:string */
	char *SOAP_ENV__Role;	/* optional element of type xsd:string */
	struct SOAP_ENV__Detail *SOAP_ENV__Detail;	/* optional element of type SOAP-ENV:Detail */
};
#endif

#endif

/******************************************************************************\
 *                                                                            *
 * Typedefs                                                                   *
 *                                                                            *
\******************************************************************************/

#ifndef SOAP_TYPE__QName
#define SOAP_TYPE__QName (5)
typedef char *_QName;
#endif

#ifndef SOAP_TYPE__XML
#define SOAP_TYPE__XML (6)
typedef char *_XML;
#endif

#ifndef SOAP_TYPE_xsd__decimal
#define SOAP_TYPE_xsd__decimal (9)
typedef std::string xsd__decimal;
#endif

#ifndef SOAP_TYPE__xsd__schema
#define SOAP_TYPE__xsd__schema (10)
typedef char *_xsd__schema;
#endif


/******************************************************************************\
 *                                                                            *
 * Externals                                                                  *
 *                                                                            *
\******************************************************************************/


/******************************************************************************\
 *                                                                            *
 * Server-Side Operations                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetQuote(struct soap*, _ns1__GetQuote *ns1__GetQuote, _ns1__GetQuoteResponse *ns1__GetQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetQuickQuote(struct soap*, _ns1__GetQuickQuote *ns1__GetQuickQuote, _ns1__GetQuickQuoteResponse *ns1__GetQuickQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetQuoteDataSet(struct soap*, _ns1__GetQuoteDataSet *ns1__GetQuoteDataSet, _ns1__GetQuoteDataSetResponse *ns1__GetQuoteDataSetResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetQuote_(struct soap*, _ns1__GetQuote *ns1__GetQuote, _ns1__GetQuoteResponse *ns1__GetQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetQuickQuote_(struct soap*, _ns1__GetQuickQuote *ns1__GetQuickQuote, _ns1__GetQuickQuoteResponse *ns1__GetQuickQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 __ns1__GetQuoteDataSet_(struct soap*, _ns1__GetQuoteDataSet *ns1__GetQuoteDataSet, _ns1__GetQuoteDataSetResponse *ns1__GetQuoteDataSetResponse);

/******************************************************************************\
 *                                                                            *
 * Server-Side Skeletons to Invoke Service Operations                         *
 *                                                                            *
\******************************************************************************/

SOAP_FMAC5 int SOAP_FMAC6 soap_serve(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve_request(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__GetQuote(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__GetQuickQuote(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__GetQuoteDataSet(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__GetQuote_(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__GetQuickQuote_(struct soap*);

SOAP_FMAC5 int SOAP_FMAC6 soap_serve___ns1__GetQuoteDataSet_(struct soap*);

/******************************************************************************\
 *                                                                            *
 * Client-Side Call Stubs                                                     *
 *                                                                            *
\******************************************************************************/


SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetQuote(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetQuote *ns1__GetQuote, _ns1__GetQuoteResponse *ns1__GetQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetQuickQuote(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetQuickQuote *ns1__GetQuickQuote, _ns1__GetQuickQuoteResponse *ns1__GetQuickQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetQuoteDataSet(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetQuoteDataSet *ns1__GetQuoteDataSet, _ns1__GetQuoteDataSetResponse *ns1__GetQuoteDataSetResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetQuote_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetQuote *ns1__GetQuote, _ns1__GetQuoteResponse *ns1__GetQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetQuickQuote_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetQuickQuote *ns1__GetQuickQuote, _ns1__GetQuickQuoteResponse *ns1__GetQuickQuoteResponse);

SOAP_FMAC5 int SOAP_FMAC6 soap_call___ns1__GetQuoteDataSet_(struct soap *soap, const char *soap_endpoint, const char *soap_action, _ns1__GetQuoteDataSet *ns1__GetQuoteDataSet, _ns1__GetQuoteDataSetResponse *ns1__GetQuoteDataSetResponse);

#endif

/* End of soapStub.h */