# include <string>
# include <stdexcept>
# include "Tag.h"

using std::string, std::vector;

Tag::Tag(string tagName) : tagName(tagName), tagPosts{} {
    if (tagName.size() < 2 || tagName[0] != '#' || tagName[1] < 97 || tagName[1] > 122) {
        throw std::invalid_argument("tagName invalid");
    }
    for (unsigned int i = 1; i < tagName.size(); i++) {
        if (isupper(tagName[i])) {
            throw std::invalid_argument("tagName invalid");
        }
        if (i == tagName.size() - 1) {
            if (tagName[i] == ('?' || ',' || '.' || '!')) {
                throw std::invalid_argument("punctuatuions at the end of the tag");
            }
        }
    }
}

string Tag::getTagName() {
    return this->tagName;
}

vector<Post*>& Tag::getTagPosts() {
    return this->tagPosts;
}

void Tag::addTagPost(Post* post) {
    if (post == nullptr) {
        throw std::invalid_argument("No posts with this tag");
    }
    tagPosts.push_back(post);
}
