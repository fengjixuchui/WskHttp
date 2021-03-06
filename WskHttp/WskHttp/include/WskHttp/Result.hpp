#include "WskHttp/Response.hpp"
#include <ntddk.h>

namespace WskHttp {
class Result {
public:
	Result(NTSTATUS status, std::string const& response) {
		status_ = status;
		response_ = Response(response);
	}

	Result(NTSTATUS status) {
		status_ = status;
	}

	Result() : status_(STATUS_UNSUCCESSFUL), response_() {}

	NTSTATUS status() {
		return status_;
	}

	Response const &response() {
		return response_;
	}

private:
	NTSTATUS status_;
	Response response_;
};
}