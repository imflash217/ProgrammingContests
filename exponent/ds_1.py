## most common words
##
import re

def most_common_words(text):
    """[summary]

    Args:
        text ([type]): [description]
    """
    ## step-1: remove punctuation, convert-to-lowercase, split by whitespaces
    ##         sanitize the text by removing caps and punctuation.
    punctuation_re = r"[.,;!\"\'\(\)]"
    sanitized_text = re.sub(punctuation_re, " ", text).lower()
    word_array = sanitized_text.split()
    word_freq = {}

    ## increment the count each time the word occurs
    for word in word_array:
        if word in word_freq.keys():
            word_freq[word] += 1
        else:
            word_freq[word] = 1

    # for word in word_array:
    #     word_freq[word] = word_freq.get(word, 0) + 1

    ## sort the words alphabetically then by their frequency
    words = sorted(word_freq.items())  ## alphabetically
    words = sorted(words, reverse=True, key=lambda x: x[1])  ## by frequency
    return words


######################################################################################################


def most_common_words_2(text):
    word_freq = {}
    start_idx = 0

    for i in range(len(text)):
        if text[i] in " .,;!\"'-()":  ## remember the SPACE in the regex
            ## we encountered end of a word
            if i > start_idx:
                word = text[start_idx:i].lower()
                word_freq[word] = word_freq.get(word, 0) + 1
            start_idx = i + 1

    ## sort the words
    words = sorted(word_freq.items())  ## alphabetical sort
    words = sorted(words, reverse=True, key=lambda x: x[1])
    return words


if __name__ == "__main__":
    text = f"It was the best of times, it was the worst of times."
    mc_words = most_common_words(text)
    mc_words_2 = most_common_words_2(text)

    print(mc_words)
    print(mc_words_2)

    assert mc_words == mc_words_2
    print("PASSED")
