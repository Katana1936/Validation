#include <iostream>
#include <regex>
#include <string>

using namespace std;

bool isValidBTC(const std::string& address) {
    std::regex btcPattern("^(1|3|bc1)[A-HJ-NP-Za-km-z1-9]{25,34}$");
    return std::regex_match(address, btcPattern);
}

bool isValidETH(const std::string& address) {
    std::regex ethPattern("^0x[a-fA-F0-9]{40}$");
    return std::regex_match(address, ethPattern);
}

bool isValidLTC(const std::string& address) {
    std::regex ltcPattern("^(L|M)[A-HJ-NP-Za-km-z1-9]{25,34}$");
    return std::regex_match(address, ltcPattern);
}

bool isValidXRP(const std::string& address) {
    std::regex xrpPattern("^r[1-9A-HJ-NP-Za-km-z]{33}$");
    return std::regex_match(address, xrpPattern);
}

bool isValidTRC20(const std::string& address) {
    std::regex trc20Pattern("^T[1-9A-HJ-NP-Za-km-z]{33}$");
    return std::regex_match(address, trc20Pattern);
}

bool isValidUSDT(const std::string& address) {
    return isValidBTC(address) || isValidETH(address) || isValidTRC20(address);
}

void validateAddress(const std::string& address) {
    if (isValidBTC(address)) {
        std::cout << "The address is a valid Bitcoin (BTC) address.\n";
    }
    else if (isValidETH(address)) {
        std::cout << "The address is a valid Ethereum (ETH) address.\n";
    }
    else if (isValidLTC(address)) {
        std::cout << "The address is a valid Litecoin (LTC) address.\n";
    }
    else if (isValidXRP(address)) {
        std::cout << "The address is a valid Ripple (XRP) address.\n";
    }
    else if (isValidUSDT(address)) {
        std::cout << "The address is a valid USDT (Tether) address.\n";
    }
    else {
        std::cout << "The address is invalid or not supported.\n";
    }
}

int main() {
    std::string address;
    std::cout << "Enter the address: ";
    std::cin >> address;

    validateAddress(address);

    std::cout << "Press any key to exit...";
    std::cin.ignore();
    std::cin.get();

    return 0;
}
