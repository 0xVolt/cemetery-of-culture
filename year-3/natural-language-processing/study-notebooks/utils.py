#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Created on Tue Mar 28 12:21:14 2023

@author: volt
"""

import string
from collections import defaultdict

def predictPOS(preprocessed, y, emission_counts, vocab, states):
    num_correct = 0
    
    # Get the (tag, word) tuples, stored as a set
    # all_words = set(emission_counts.keys())
    
    # Get the number of (word, POS) tuples in the corpus 'y'
    total = len(y)
    
    for word, y_tup in zip(preprocessed, y): 
        y_tup_l = y_tup.split()
        if len(y_tup_l) == 2:
            true_label = y_tup_l[1]
        else:
            # If the y_tup didn't contain word and POS, go to next word
            continue
        
        count_final = 0
        pos_final = ''
        if word in vocab:
            for pos in states:
                key = (pos,word)
                if key in emission_counts: 
                    count = emission_counts[key]

                    if count>count_final:
                        count_final = count
                        pos_final = pos

            if pos_final == true_label:
                num_correct += 1
    
    accuracy = num_correct / total
    return accuracy

def createDictionaries(training_corpus, vocab):
    emission_counts = defaultdict(int)
    transition_counts = defaultdict(int)
    tag_counts = defaultdict(int)
    
    # Initialize "prev_tag" (previous tag) with the start state, denoted by '--s--'
    prev_tag = '--s--' 
    i = 0 
    
    # Each item in the training corpus contains a word and its POS tag
    # Go through each word and its tag in the training corpus
    for word_tag in training_corpus:
        
        # Increment the word_tag count
        i += 1
    
        # get the word and tag using the getWordTag helper function 
        word, tag = getWordTag(word_tag,vocab) 
        
        # Increment the transition count for the previous word and tag
        transition_counts[(prev_tag, tag)] += 1
        
        # Increment the emission count for the tag and word
        emission_counts[(tag, word)] += 1

        # Increment the tag count
        tag_counts[tag] += 1

        # Set the previous tag to this tag (for the next iteration of the loop)
        prev_tag = tag
        
    return emission_counts, transition_counts, tag_counts

def preprocess(vocab, data_fp):
    orig = []
    prep = []

    with open(data_fp, "r") as data_file:
        for cnt, word in enumerate(data_file):
            if not word.split():
                orig.append(word.strip())
                word = "--n--"
                prep.append(word)
                continue
            # Handle unknown words
            elif word.strip() not in vocab:
                orig.append(word.strip())
                word = assignUnknownTags(word)
                prep.append(word)
                continue
            else:
                orig.append(word.strip())
                prep.append(word.strip())

    assert(len(orig) == len(open(data_fp, "r").readlines()))
    assert(len(prep) == len(open(data_fp, "r").readlines()))

    return orig, prep

def getWordTag(line, vocab):
    # If line is empty return placeholders for word and tag
    if not line.split():
        word = "--n--"
        tag = "--s--"
    else:
        word, tag = line.split()
        
        # Handling unknown words 
        if word not in vocab: 
            word = assignUnknownTags(word)
    
    return word, tag


def assignUnknownTags(word):

    punct = set(string.punctuation)
    
    # Suffixes
    noun_suffix = ["action", "age", "ance", "cy", "dom", "ee", "ence", "er", "hood", "ion", "ism", "ist", "ity", "ling", "ment", "ness", "or", "ry", "scape", "ship", "ty"]
    verb_suffix = ["ate", "ify", "ise", "ize"]
    adj_suffix = ["able", "ese", "ful", "i", "ian", "ible", "ic", "ish", "ive", "less", "ly", "ous"]
    adv_suffix = ["ward", "wards", "wise"]

    if any(char.isdigit() for char in word):
        return "--unk_digit--"
    
    elif any(char in punct for char in word):
        return "--unk_punct--"
    
    elif any(char.isupper() for char in word):
        return "--unk_upper--"

    elif any(word.endswith(suffix) for suffix in noun_suffix):
        return "--unk_noun--"

    elif any(word.endswith(suffix) for suffix in verb_suffix):
        return "--unk_verb--"

    elif any(word.endswith(suffix) for suffix in adj_suffix):
        return "--unk_adj--"

    elif any(word.endswith(suffix) for suffix in adv_suffix):
        return "--unk_adv--"
    
    return "--unk--"
