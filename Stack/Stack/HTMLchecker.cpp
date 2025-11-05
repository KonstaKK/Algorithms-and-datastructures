#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cctype>

class Stack {
private:
    std::vector<std::string> elements;

public:
    void push(const std::string& item) {
        elements.push_back(item);
    }

    void pop() {
        if (!isEmpty())
            elements.pop_back();
    }

    std::string top() const {
        if (!isEmpty())
            return elements.back();
        return "";
    }

    bool isEmpty() const {
        return elements.empty();
    }
};

// Trim leading/trailing whitespace
std::string trim(const std::string& str) {
    size_t start = str.find_first_not_of(" \t\n\r");
    size_t end = str.find_last_not_of(" \t\n\r");
    if (start == std::string::npos || end == std::string::npos)
        return "";
    return str.substr(start, end - start + 1);
}

// Convert string to lowercase
std::string toLower(const std::string& s) {
    std::string out = s;
    std::transform(out.begin(), out.end(), out.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return out;
}

// Check if tag is one of the HTML5 void elements
bool isVoidElement(const std::string& tag) {
    static const std::vector<std::string> voidTags = {
        "area", "base", "br", "col", "embed", "hr", "img",
        "input", "link", "meta", "source", "track", "wbr"
    };

    for (const auto& t : voidTags)
        if (t == tag)
            return true;

    return false;
}

bool checkHTMLSyntax(const std::string& filename) {
    std::ifstream file(filename);
    if (!file) {
        std::cerr << "Error: Could not open file '" << filename << "'\n";
        return false;
    }

    Stack tagStack;
    std::vector<std::string> debugTags;  // log of all tags
    std::string line;
    int lineNum = 0;

    while (std::getline(file, line)) {
        lineNum++;
        size_t pos = 0;

        while ((pos = line.find('<', pos)) != std::string::npos) {
            size_t end = line.find('>', pos + 1);
            if (end == std::string::npos) {
                std::cerr << "Error: Unclosed tag on line " << lineNum << "\n";
                return false;
            }

            std::string rawTag = line.substr(pos + 1, end - pos - 1);
            rawTag = trim(rawTag);

            // Skip empty or comment tags
            if (rawTag.empty() || rawTag.rfind("!--", 0) == 0) {
                pos = end + 1;
                continue;
            }

            bool closing = false;
            if (rawTag[0] == '/') {
                closing = true;
                rawTag = trim(rawTag.substr(1)); // remove '/' and trim again
            }

            // Remove attributes or anything after first space or tab
            size_t spacePos = rawTag.find_first_of(" \t");
            if (spacePos != std::string::npos)
                rawTag = rawTag.substr(0, spacePos);

            // Convert to lowercase
            std::string tagName = toLower(trim(rawTag));

            // Skip if self-closing (void) tag
            if (isVoidElement(tagName)) {
                debugTags.push_back("<" + tagName + " />");
                pos = end + 1;
                continue;
            }

            // Process normal tags
            if (!closing) {
                debugTags.push_back("<" + tagName + ">");
                tagStack.push(tagName);
            }
            else {
                debugTags.push_back("</" + tagName + ">");
                if (tagStack.isEmpty() || tagStack.top() != tagName) {
                    std::cerr << "Error: Mismatched or unexpected closing tag </"
                        << tagName << "> on line " << lineNum << "\n";
                    return false;
                }
                tagStack.pop();
            }

            pos = end + 1;
        }
    }

    if (!tagStack.isEmpty()) {
        std::cerr << "Error: Missing closing tag for <" << tagStack.top() << ">\n";
        return false;
    }

    // If we reach here, everything matched
    std::cout << "HTML syntax check passed!\n\n";

    std::cout << "--- Debug: Tags Encountered ---\n";
    for (const auto& tag : debugTags)
        std::cout << tag << '\n';

    return true;
}

int main() {
    std::string filename = "Your Title Here.html";
    std::string newFilename = "webpage1.html";

    std::cout << "First file: " << std::endl;
    checkHTMLSyntax(filename);

    std::cout << std::endl;
    std::cout << "Second file: " << std::endl;
    checkHTMLSyntax(newFilename);
    return 0;
}

// ChatGPT was used in writing the code