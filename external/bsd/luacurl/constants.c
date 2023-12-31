/*
 * Copyright (c) 2013 - 2020 Micro Systems Marc Balmer, CH-5073 Gipf-Oberfrick
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of Micro Systems Marc Balmer nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL MICRO SYSTEMS MARC BALMER BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/* CURL constants */

#include <lua.h>

#include <curl/curl.h>

#include "luacurl.h"

#define CURL(NAME)		{ #NAME, CURL##NAME }
#define CURL_(NAME)		{ #NAME, CURL_##NAME }

#define CURLE_(NAME)		{ #NAME, CURLE_##NAME }

struct int_constant curl_int[] = {
	CURLE_(OK),
	CURLE_(UNSUPPORTED_PROTOCOL),
	CURLE_(FAILED_INIT),
	CURLE_(URL_MALFORMAT),
	CURLE_(URL_MALFORMAT_USER),
	CURLE_(COULDNT_RESOLVE_PROXY),
	CURLE_(COULDNT_RESOLVE_HOST),
	CURLE_(COULDNT_CONNECT),
	CURLE_(FTP_WEIRD_SERVER_REPLY),
	CURLE_(FTP_ACCESS_DENIED),
	CURLE_(FTP_USER_PASSWORD_INCORRECT),
	CURLE_(FTP_WEIRD_PASS_REPLY),
	CURLE_(FTP_WEIRD_USER_REPLY),
	CURLE_(FTP_WEIRD_PASV_REPLY),
	CURLE_(FTP_WEIRD_227_FORMAT),
	CURLE_(FTP_CANT_GET_HOST),
	CURLE_(FTP_CANT_RECONNECT),
	CURLE_(FTP_COULDNT_SET_BINARY),
	CURLE_(PARTIAL_FILE),
	CURLE_(FTP_COULDNT_RETR_FILE),
	CURLE_(FTP_WRITE_ERROR),
	CURLE_(FTP_QUOTE_ERROR),
	CURLE_(HTTP_RETURNED_ERROR),
	CURLE_(WRITE_ERROR),
	CURLE_(MALFORMAT_USER),
	CURLE_(FTP_COULDNT_STOR_FILE),
	CURLE_(READ_ERROR),
	CURLE_(OUT_OF_MEMORY),
	CURLE_(OPERATION_TIMEOUTED),
	CURLE_(FTP_COULDNT_SET_ASCII),
	CURLE_(FTP_PORT_FAILED),
	CURLE_(FTP_COULDNT_USE_REST),
	CURLE_(FTP_COULDNT_GET_SIZE),
	CURLE_(HTTP_RANGE_ERROR),
	CURLE_(HTTP_POST_ERROR),
	CURLE_(SSL_CONNECT_ERROR),
	CURLE_(BAD_DOWNLOAD_RESUME),
	CURLE_(FILE_COULDNT_READ_FILE),
	CURLE_(LDAP_CANNOT_BIND),
	CURLE_(LDAP_SEARCH_FAILED),
	CURLE_(LIBRARY_NOT_FOUND),
	CURLE_(FUNCTION_NOT_FOUND),
	CURLE_(ABORTED_BY_CALLBACK),
	CURLE_(BAD_FUNCTION_ARGUMENT),
	CURLE_(BAD_CALLING_ORDER),
	CURLE_(INTERFACE_FAILED),
	CURLE_(BAD_PASSWORD_ENTERED),
	CURLE_(TOO_MANY_REDIRECTS),
	CURLE_(UNKNOWN_TELNET_OPTION),
	CURLE_(TELNET_OPTION_SYNTAX),
	CURLE_(OBSOLETE),
	CURLE_(SSL_PEER_CERTIFICATE),
	CURLE_(GOT_NOTHING),
	CURLE_(SSL_ENGINE_NOTFOUND),
	CURLE_(SSL_ENGINE_SETFAILED),
	CURLE_(SEND_ERROR),
	CURLE_(RECV_ERROR),
	CURLE_(SHARE_IN_USE),
	CURLE_(SSL_CERTPROBLEM),
	CURLE_(SSL_CIPHER),
	CURLE_(SSL_CACERT),
	CURLE_(BAD_CONTENT_ENCODING),
	CURLE_(LDAP_INVALID_URL),
	CURLE_(FILESIZE_EXCEEDED),
	CURLE_(FTP_SSL_FAILED),
	CURLE_(SEND_FAIL_REWIND),
	CURLE_(SSL_ENGINE_INITFAILED),
	CURLE_(LOGIN_DENIED),

#if CURL_NEWER(7,12,1)
	CURL_(READFUNC_ABORT),
#endif

#if CURL_NEWER(7,12,3)
	/* enum curlioerr */
	CURL(IOE_OK),
	CURL(IOE_UNKNOWNCMD),
	CURL(IOE_FAILRESTART),

	/* enum curliocmd */
	CURL(IOCMD_NOP),
	CURL(IOCMD_RESTARTREAD),
#endif

	/* enum curl_proxytype */
	CURL(PROXY_HTTP),
#if CURL_NEWER(7,19,3)
	CURL(PROXY_HTTP_1_0),
#endif
#if CURL_NEWER(7,52,0)
	CURL(PROXY_HTTPS),
#endif
	CURL(PROXY_SOCKS4),
	CURL(PROXY_SOCKS5),
	CURL(PROXY_SOCKS4A),
	CURL(PROXY_SOCKS5_HOSTNAME),

	/* auth types */
	CURL(AUTH_NONE),
	CURL(AUTH_BASIC),
	CURL(AUTH_DIGEST),
	CURL(AUTH_GSSNEGOTIATE),
	CURL(AUTH_NTLM),
	CURL(AUTH_DIGEST_IE),
#if CURL_NEWER(7,21,4)
	CURL(AUTH_NTLM_WB),
#endif
#if CURL_NEWER(7,21,1)
	CURL(AUTH_ONLY),
#endif
	CURL(AUTH_ANY),
	CURL(AUTH_ANYSAFE),

	CURL(SSH_AUTH_ANY),
	CURL(SSH_AUTH_NONE),
	CURL(SSH_AUTH_PUBLICKEY),
	CURL(SSH_AUTH_PASSWORD),
	CURL(SSH_AUTH_HOST),
	CURL(SSH_AUTH_KEYBOARD),
#if CURL_NEWER(7,27,1)
	CURL(SSH_AUTH_AGENT),
#endif
	CURL(SSH_AUTH_DEFAULT),

#if CURL_NEWER(7,21,4)
	CURL(GSSAPI_DELEGATION_NONE),
	CURL(GSSAPI_DELEGATION_POLICY_FLAG ),
	CURL(GSSAPI_DELEGATION_FLAG),
#endif

	/* parameter for the CURLOPT_USE_SSL option */
	CURL(USESSL_NONE),
	CURL(USESSL_TRY),
	CURL(USESSL_CONTROL),
	CURL(USESSL_ALL),

	/* enum curl_ftpssl */
	CURL(FTPSSL_NONE),
	CURL(FTPSSL_TRY),
	CURL(FTPSSL_CONTROL),
	CURL(FTPSSL_ALL),

#if CURL_NEWER(7,12,2)
	/* enum curl_ftpauth */
	CURL(FTPAUTH_DEFAULT),
	CURL(FTPAUTH_SSL),
	CURL(FTPAUTH_TLS),
#endif

	/* ip resolve options */
	CURL_(IPRESOLVE_WHATEVER),
	CURL_(IPRESOLVE_V4),
	CURL_(IPRESOLVE_V6),

	/* http versions */
	CURL_(HTTP_VERSION_NONE),
	CURL_(HTTP_VERSION_1_0),
	CURL_(HTTP_VERSION_1_1),

	/* CURL_NETRC_OPTION */
	CURL_(NETRC_IGNORED),
	CURL_(NETRC_OPTIONAL),
	CURL_(NETRC_REQUIRED),

	/* ssl version */
	CURL_(SSLVERSION_DEFAULT),
	CURL_(SSLVERSION_TLSv1),
	CURL_(SSLVERSION_SSLv2),
	CURL_(SSLVERSION_SSLv3),

#if CURL_NEWER(7,21,4)
	CURL_(TLSAUTH_NONE),
	CURL_(TLSAUTH_SRP),
#endif

	CURL_(REDIR_GET_ALL),
	CURL_(REDIR_POST_301),
	CURL_(REDIR_POST_302),
#if CURL_NEWER(7,22,1)
	CURL_(REDIR_POST_303),
#endif
	CURL_(REDIR_POST_ALL),

	/* CURLOPT_TIMECONDITION */
	CURL_(TIMECOND_NONE),
	CURL_(TIMECOND_IFMODSINCE),
	CURL_(TIMECOND_IFUNMODSINCE),
	CURL_(TIMECOND_LASTMOD),

	/* enum CURLformoption */
	CURL(FORM_COPYNAME),
	CURL(FORM_PTRNAME),
	CURL(FORM_NAMELENGTH),
	CURL(FORM_COPYCONTENTS),
	CURL(FORM_PTRCONTENTS),
	CURL(FORM_CONTENTSLENGTH),
	CURL(FORM_FILECONTENT),
	CURL(FORM_ARRAY),
	CURL(FORM_OBSOLETE),
	CURL(FORM_FILE),
	CURL(FORM_BUFFER),
	CURL(FORM_BUFFERPTR),
	CURL(FORM_BUFFERLENGTH),
	CURL(FORM_CONTENTTYPE),
	CURL(FORM_CONTENTHEADER),
	CURL(FORM_FILENAME),
	CURL(FORM_END),
	CURL(FORM_OBSOLETE2),

	/* enum CURLFORMcode*/
	CURL_(FORMADD_OK),
	CURL_(FORMADD_MEMORY),
	CURL_(FORMADD_OPTION_TWICE),
	CURL_(FORMADD_NULL),
	CURL_(FORMADD_UNKNOWN_OPTION),
	CURL_(FORMADD_INCOMPLETE),
	CURL_(FORMADD_ILLEGAL_ARRAY),
#if CURL_NEWER(7,12,1)
	CURL_(FORMADD_DISABLED),
#endif

	/* version info flags */
#if CURL_NEWER(7,10,0)
	CURL_(VERSION_LIBZ),
	CURL_(VERSION_SSL),
#endif
#if CURL_NEWER(7,10,6)
	CURL_(VERSION_DEBUG),
	CURL_(VERSION_GSSNEGOTIATE),
	CURL_(VERSION_NTLM),
#endif
#if CURL_NEWER(7,10,7)
	CURL_(VERSION_ASYNCHDNS),
#endif
#if CURL_NEWER(7,10,8)
	CURL_(VERSION_SPNEGO),
#endif
#if CURL_NEWER(7,11,1)
	CURL_(VERSION_LARGEFILE),
#endif
#if CURL_NEWER(7,12,0)
	CURL_(VERSION_IDN),
#endif
#if CURL_NEWER(7,13,2)
	CURL_(VERSION_SSPI),
#endif
#if CURL_NEWER(7,15,4)
	CURL_(VERSION_CONV),
#endif
#if CURL_NEWER(7,19,6)
	CURL_(VERSION_CURLDEBUG),
#endif
#if CURL_NEWER(7,21,4)
	CURL_(VERSION_TLSAUTH_SRP),
#endif
#if CURL_NEWER(7,22,0)
	CURL_(VERSION_NTLM_WB),
#endif
#if CURL_NEWER(7,33,0)
	CURL_(VERSION_HTTP2),
#endif
#if CURL_NEWER(7,38,0)
	CURL_(VERSION_GSSAPI),
#endif
#if CURL_NEWER(7,40,0)
	CURL_(VERSION_KERBEROS5),
	CURL_(VERSION_UNIX_SOCKETS),
#endif
#if CURL_NEWER(7,47,0)
	CURL_(VERSION_PSL),
#endif
#if CURL_NEWER(7,52,0)
	CURL_(VERSION_HTTPS_PROXY),
#endif
#if CURL_NEWER(7,56,0)
	CURL_(VERSION_MULTI_SSL),
#endif
#if CURL_NEWER(7,57,0)
	CURL_(VERSION_BROTLI),
#endif
#if CURL_NEWER(7,64,1)
	CURL_(VERSION_ALTSVC),
#endif
#if CURL_NEWER(7,66,1)
	CURL_(VERSION_HTTP3),
#endif
	CURL_(VERSION_IPV6),
	CURL_(VERSION_KERBEROS4),

	/* INFO */
	CURL(INFO_NONE),
	CURL(INFO_EFFECTIVE_URL),
	CURL(INFO_RESPONSE_CODE),
	CURL(INFO_TOTAL_TIME),
	CURL(INFO_NAMELOOKUP_TIME),
	CURL(INFO_CONNECT_TIME),
	CURL(INFO_PRETRANSFER_TIME),
	CURL(INFO_SIZE_UPLOAD),
	CURL(INFO_SIZE_DOWNLOAD),
	CURL(INFO_SPEED_DOWNLOAD),
	CURL(INFO_SPEED_UPLOAD),
	CURL(INFO_HEADER_SIZE),
	CURL(INFO_REQUEST_SIZE),
	CURL(INFO_SSL_VERIFYRESULT),
	CURL(INFO_FILETIME),
	CURL(INFO_CONTENT_LENGTH_DOWNLOAD),
	CURL(INFO_CONTENT_LENGTH_UPLOAD),
	CURL(INFO_STARTTRANSFER_TIME),
	CURL(INFO_CONTENT_TYPE),
	CURL(INFO_REDIRECT_TIME),
	CURL(INFO_REDIRECT_COUNT),
	CURL(INFO_PRIVATE),
	CURL(INFO_HTTP_CONNECTCODE),
	CURL(INFO_HTTPAUTH_AVAIL),
	CURL(INFO_PROXYAUTH_AVAIL),
	CURL(INFO_OS_ERRNO),
	CURL(INFO_NUM_CONNECTS),
	CURL(INFO_SSL_ENGINES),
	CURL(INFO_COOKIELIST),
#if CURL_NEWER(7,15,2)
	CURL(INFO_LASTSOCKET),
#endif
	CURL(INFO_FTP_ENTRY_PATH),
	CURL(INFO_REDIRECT_URL),
	CURL(INFO_PRIMARY_IP),
	CURL(INFO_APPCONNECT_TIME),
	CURL(INFO_CERTINFO),
	CURL(INFO_CONDITION_UNMET),
#if CURL_NEWER(7,19,8)
	CURL(INFO_RTSP_SESSION_ID),
	CURL(INFO_RTSP_CLIENT_CSEQ),
	CURL(INFO_RTSP_SERVER_CSEQ),
	CURL(INFO_RTSP_CSEQ_RECV),
	CURL(INFO_PRIMARY_PORT),
	CURL(INFO_LOCAL_IP),
	CURL(INFO_LOCAL_PORT),
#endif
	/* enum curl_closepolicy*/
	CURL(CLOSEPOLICY_OLDEST),
	CURL(CLOSEPOLICY_LEAST_RECENTLY_USED),
	CURL(CLOSEPOLICY_LEAST_TRAFFIC),
	CURL(CLOSEPOLICY_SLOWEST),
	CURL(CLOSEPOLICY_CALLBACK),

	CURL(VERSION_FIRST),
	CURL(VERSION_SECOND),
	CURL(VERSION_THIRD),
	CURL(VERSION_FOURTH),
#ifdef CURLVERSION_FIFTH
	CURL(VERSION_FIFTH),
#endif
#if CURL_NEWER(7,66,0)
	CURL(VERSION_SIXTH),
#endif
	CURL(VERSION_NOW)
};

size_t
num_curl_int(void)
{
	return sizeof(curl_int)/sizeof(curl_int[0]);
}
