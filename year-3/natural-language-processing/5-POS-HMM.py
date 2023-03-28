# %% Import libraries | Start of the program

import pandas as pd
from collections import defaultdict
from collections import Counter
import math
import numpy as np
import string

# from utils import assignUnknownTags, getWordTag, preprocessedrocess, createDictionaries, predictPOS

# %% Declaration of functions

def create_emission_matrix(alpha, tag_counts, emission_counts, vocab):
    
    num_tags = len(tag_counts)
    all_tags = sorted(tag_counts.keys())
    num_words = len(vocab)
    B = np.zeros((num_tags, num_words))

#     emis_keys = set(list(emission_counts.keys()))
    
    for i in range(num_tags):
        for j in range(num_words):
            count = 0
            key =  (all_tags[i],vocab[j])
            if key in emission_counts.keys():
                count = emission_counts[key]
            count_tag = tag_counts[all_tags[i]]
            
            B[i,j] = (count + alpha) / (count_tag+ alpha*num_words)
    return B


def viterbi_backward(best_probs, best_paths, corpus, states):
    '''
    This function returns the best path.
    
    '''
    # Get the number of words in the corpus
    # which is also the number of columns in best_probs, best_paths
    m = best_paths.shape[1] 
    
    # Initialize array z, same length as the corpus
    z = [None] * m
    
    # Get the number of unique POS tags
    num_tags = best_probs.shape[0]
    
    # Initialize the best probability for the last word
    best_prob_for_last_word = float('-inf')
    
    # Initialize pred array, same length as corpus
    pred = [None] * m
    
    ### START CODE HERE (Replace instances of 'None' with your code) ###
    ## Step 1 ##
    
    # Go through each POS tag for the last word (last column of best_probs)
    # in order to find the row (POS tag integer ID) 
    # with highest probability for the last word
    for k in range(num_tags): # complete this line

        # If the probability of POS tag at row k 
        # is better than the previosly best probability for the last word:
        if best_probs[k,-1]>best_prob_for_last_word: # complete this line
            
            # Store the new best probability for the lsat word
            best_prob_for_last_word = best_probs[k,-1]
    
            # Store the unique integer ID of the POS tag
            # which is also the row number in best_probs
            z[m - 1] = k
            
    # Convert the last word's predicted POS tag
    # from its unique integer ID into the string representation
    # using the 'states' dictionary
    # store this in the 'pred' array for the last word
    pred[m - 1] = states[k]
    
    ## Step 2 ##
    # Find the best POS tags by walking backward through the best_paths
    # From the last word in the corpus to the 0th word in the corpus
    for i in range(len(corpus)-1, -1, -1): # complete this line
        
        # Retrieve the unique integer ID of
        # the POS tag for the word at position 'i' in the corpus
        pos_tag_for_word_i = best_paths[np.argmax(best_probs[:,i]),i]
        
        # In best_paths, go to the row representing the POS tag of word i
        # and the column representing the word's position in the corpus
        # to retrieve the predicted POS for the word at position i-1 in the corpus
        z[i - 1] = best_paths[pos_tag_for_word_i,i]
        
        # Get the previous word's POS tag in string form
        # Use the 'states' dictionary, 
        # where the key is the unique integer ID of the POS tag,
        # and the value is the string representation of that POS tag
        pred[i - 1] = states[pos_tag_for_word_i]
        
     ### END CODE HERE ###
    return pred


# UNQ_C8 (UNIQUE CELL IDENTIFIER, DO NOT EDIT) | GRADED FUNCTION: compute_accuracy
def compute_accuracy(pred, y):
    '''
    Input: 
        pred: a list of the predicted parts-of-speech 
        y: a list of lines where each word is separated by a '\t' (i.e. word \t tag)
    Output: 
        
    '''
    num_correct = 0
    total = 0
    
    # Zip together the prediction and the labels
    for prediction, y in zip(pred, y):
        ### START CODE HERE (Replace instances of 'None' with your code) ###
        # Split the label into the word and the POS tag
        word_tag_tuple = y.split()
        
        # Check that there is actually a word and a tag
        # no more and no less than 2 items
        if len(word_tag_tuple)!=2: # complete this line
            continue 

        # store the word and tag separately
        word, tag = word_tag_tuple
        
        # Check if the POS tag label matches the prediction
        if prediction == tag: # complete this line
            
            # count the number of times that the prediction
            # and label match
            num_correct += 1
            
        # keep track of the total number of examples (that have valid labels)
        total += 1
        
        ### END CODE HERE ###
    return num_correct/total


# UNQ_C6 (UNIQUE CELL IDENTIFIER, DO NOT EDIT)
# GRADED FUNCTION: viterbi_forward

def viterbi_forward(A, B, test_corpus, best_probs, best_paths, vocab):
    '''
    Input: 
        A, B: The transiton and emission matrices respectively
        test_corpus: a list containing a preprocessedrocessed corpus
        best_probs: an initilized matrix of dimension (num_tags, len(corpus))
        best_paths: an initilized matrix of dimension (num_tags, len(corpus))
        vocab: a dictionary where keys are words in vocabulary and value is an index 
    Output: 
        best_probs: a completed matrix of dimension (num_tags, len(corpus))
        best_paths: a completed matrix of dimension (num_tags, len(corpus))
    '''
    # Get the number of unique POS tags (which is the num of rows in best_probs)
    num_tags = best_probs.shape[0]
 
    for i in range(1, len(test_corpus)): 
        for j in range(num_tags):
            
            best_prob_i = float("-inf")
            best_path_i = None

            for k in range(num_tags):
                prob = best_probs[k,i-1]+math.log(A[k,j]) +math.log(B[j,vocab[test_corpus[i]]])
                
                if prob > best_prob_i:
                    best_prob_i = prob
                    best_path_i = k
                    
            best_probs[j,i] = best_prob_i
            best_paths[j,i] = best_path_i

    return best_probs, best_paths

def initialize(states, tag_counts, A, B, corpus, vocab):
    '''
    Input: 
        states: a list of all possible parts-of-speech
        tag_counts: a dictionary mapping each tag to its respective count
        A: Transition Matrix of dimension (num_tags, num_tags)
        B: Emission Matrix of dimension (num_tags, len(vocab))
        corpus: a sequence of words whose POS is to be identified in a list 
        vocab: a dictionary where keys are words in vocabulary and value is an index
    Output:
        best_probs: matrix of dimension (num_tags, len(corpus)) of floats
        best_paths: matrix of dimension (num_tags, len(corpus)) of integers
    '''
   
    num_tags = len(tag_counts)
    
    best_probs = np.zeros((num_tags, len(corpus)))
    best_paths = np.zeros((num_tags, len(corpus)), dtype=int)
    
    # Index for the <start> tag
    s_idx = states.index("--s--")
    
    # Checking the probability of a tag given the <start> tag occurring first 
    for i in range(num_tags):
        
        if A[s_idx,i] == 0: 
            
            # Initialize best_probs at POS tag 'i', column 0, to negative infinity
            best_probs[i,0] = float('-inf')
        
        # For all other cases when transition from start token to POS tag i is non-zero:
        else:
            # Initialize best_probs at POS tag 'i', column 0
            # Check the formula in the instructions above
            best_probs[i, 0] = math.log(A[s_idx, i]) + math.log(B[i, vocab[corpus[0]]])
                        

    return best_probs, best_paths

def create_transition_matrix(alpha, tag_counts, transition_counts):
 
    all_tags = sorted(tag_counts.keys()) 
    num_tags = len(all_tags)
    A = np.zeros((num_tags,num_tags))
    
    # trans_keys = set(transition_counts.keys())
    
    for i in range(num_tags):
        for j in range(num_tags):
            count = 0
            key = (all_tags[i],all_tags[j])
            if transition_counts: 
                count = transition_counts[key]
            count_prev_tag = tag_counts[all_tags[i]]
            A[i,j] = (count + alpha) / (count_prev_tag + alpha*num_tags)

    return A

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


# %% Create Vocab from the training data and save it to hmm_vocab.txt

with open(r"/home/volt/code/NLP-class-notebooks/data/WSJ_02-21.pos", 'r') as f:
    lines = f.readlines()

print('First 5 lines read from the \'WSJ_02-21.pos\' file:\n', lines[:5], end='')

# %% Creating list of words, frequencyDictionary and vocabulary

# Splitting the lines read by '\t'
words = [line.split('\t')[0] for line in lines]

# Using a counter to derive a frequency dictionary
frequencyDictionary = Counter(words)

# Creating a vocabulary list using the dictionary we just derived
# Only those values of count that are greater than 2 and aren't a new line character, are considered
vocab = [key for key, value in frequencyDictionary.items() if (value > 2 and key != '\n')]
vocab.sort()

# %% Printing out the first 5 elements in our frequency dictionary

# Enumerating over the dictionary to get an index
print('Printing the first 5 elements in our sorted dictionary of frequencies:')
for i, item in enumerate(frequencyDictionary.items()):
    print(item)
    
    if i > 5:
        break

# %% Using the set of punctuation marks from the string library

print(f'Here are the set of punctuation marks in the string library:\n{set(string.punctuation)}\nLength: {len(set(string.punctuation))}')

# %% Getting tags for words using our getWordTag() function passing our vocab

print('\\n ->', getWordTag('\n', vocab))

print('In\\tIN\\n ->', getWordTag('In\tIN\n', vocab))

print('tardigrade\\tNN\\n ->', getWordTag('tardigrade\tNN\n', vocab))

# %% Loading training data and the vocabulary

# Load training data
with open(r"/home/volt/code/NLP-class-notebooks/data/WSJ_02-21.pos", 'r') as f:
    trainingCorpus = f.readlines()

# Load vocab
with open(r"/home/volt/code/NLP-class-notebooks/data/vocab.txt", 'r') as f:
    loadedVocab = f.read().split('\n')

# %%

loadedVocab[:10]

# %% Creating our vocab wherein the dictionary that has the index of the corresponding words

vocab = {} 
for i, word in enumerate(sorted(loadedVocab)): 
    vocab[word] = i       

# %%

print('Printing the length of the vocabluary set:', len(vocab))

# %%

print("Printing the vocabulary dictionary where key is the word and the value is a unique integer.")

count = 0
for key, value in vocab.items():
    print(f"{key}: {value}")
    
    count += 1
    if count > 5:
        break

# %% Loading the test corpus

with open("/home/volt/code/NLP-class-notebooks/data/WSJ_24.pos", 'r') as f:
    y = f.readlines()

print(y[0:10])

# %% Getting preprocessedrocessed tags

original, preprocessed = preprocess(vocab, "/home/volt/code/NLP-class-notebooks/data/test.words")
print(preprocessed[600:800])

# %% Printing out preprocessedrocessed tags

print(original[600:650])

# %%

emission_counts, transition_counts, tag_counts = createDictionaries(trainingCorpus, vocab)

# %%

print("transition_counts\n")
cnt = 0
for k,v in transition_counts.items():
    print(f"{k}:{v}")
    cnt += 1
    if cnt > 5:
        break

# %%

print("emission_counts\n")
cnt = 0
for k,v in emission_counts.items():
    print(f"{k}:{v}")
    cnt += 1
    if cnt > 5:
        break

# %%

print("tag_counts\n")
cnt = 0
for k,v in tag_counts.items():
    print(f"{k}:{v}")
    cnt += 1
    if cnt > 5:
        break

# %% Get all the states from the POS

states = sorted(tag_counts.keys())

print(len(states))
print(states)

# %%

print("Transition examples: ")
for ex in list(transition_counts.items())[:3]:
    print(ex)
print()

print("Emission examples: ")
for ex in list(emission_counts.items())[200:203]:
    print (ex)
print()

print("Ambiguous Word example: ")
for tup,cnt in emission_counts.items():
    if tup[1] == 'back': print (tup, cnt) 

# %% Print actual data points from the testing dataset

print(y[:10])

# %% The test set is completely preprocessed to get words

print(preprocessed[:10])

# %% Printing the length of the actual and preprocessed words

print('Printing the length of the actual and preprocessed words:', len(y), len(preprocessed))


# %%
accuracy_predictPOS = predictPOS(preprocessed, y, emission_counts, vocab, states)
print(f"Accuracy of prediction using predictPOS is {accuracy_predictPOS:.4f}")

# %%

print("tag_counts\n")
cnt = 0
for k,v in tag_counts.items():
    print(f"{k}:{v}")
    cnt += 1
    if cnt > 5:
        break

# %%

all_tags = sorted(tag_counts.keys()) 
print(all_tags)
# print(len(all_tags))
# count_prev_tag = tag_counts[all_tags[i]]
count_prev_tag = tag_counts['#']
print(count_prev_tag)
print(transition_counts[('#', '#')])
print(transition_counts[('#', '$')])

# %%

print("transition count dictionary values ")
for ex in list(transition_counts.items())[:3]:
    print(ex)
print()
trans_keys = set(transition_counts.keys())
cnt = 0

# %%

alpha = 0.001
A = create_transition_matrix(alpha, tag_counts, transition_counts)
# Testing your function
print(f"A at row 0, col 0: {A[0,0]:.9f}")
print(f"A at row 3, col 1: {A[3,1]:.4f}")

print("View a subset of transition matrix A")
A_sub = pd.DataFrame(A[30:35,30:35], index=states[30:35], columns = states[30:35] )
print(A_sub)

# %%

print("emission examples: ")
for ex in list(emission_counts.items())[200:203]:
    print (ex)
print()

# %%

num_words = len(vocab)
print(num_words)
# print(type(vocab))
# print(vocab)
print("vocab is a dictionary where key is the word, value is a unique integer")
cnt = 0
for k,v in vocab.items():
    print(f"{k}:{v}")
    cnt += 1
    if cnt > 5:
        break
print(list(vocab)[:5])

# %%
# creating your emission probability matrix. this takes a few minutes to run. 
B = create_emission_matrix(alpha, tag_counts, emission_counts, list(vocab))

print(f"View Matrix position at row 0, column 0: {B[0,0]:.9f}")
print(f"View Matrix position at row 3, column 1: {B[3,1]:.9f}")

# Try viewing emissions for a few words in a sample dataframe
cidx  = ['725','adroitly','engineers', 'promoted', 'synergy']

# Get the integer ID for each word
cols = [vocab[a] for a in cidx]

# Choose POS tags to show in a sample dataframe
rvals =['CD','NN','NNS', 'VB','RB','RP']

# For each POS tag, get the row number from the 'states' list
rows = [states.index(a) for a in rvals]

# Get the emissions for the sample of words, and the sample of POS tags
B_sub = pd.DataFrame(B[np.ix_(rows,cols)], index=rvals, columns = cidx )
print(B_sub)

# %%

preprocessed[0]

# %%

len(preprocessed)

# %%

print(preprocessed[:10])
print(preprocessed[0])
vocab['The']
s_idx = states.index("--s--")
print(states)
print(s_idx)

# %%

print(math.log(A[6,0])+math.log(B[0,8614]))
print(math.log(A[6,11])+math.log(B[11,8614]))

# %%

print(vocab['The'])
print(B[0,8614])
print(B[11,8614])

# %%

states, len(states)

# %%

best_probs, best_paths = initialize(states, tag_counts, A, B, preprocessed, vocab)

# %%

best_probs.shape

# %% Print first column of the best_prob matrix 
for i in range(len(states)):
    print(f"best_probs[{i},0]: {best_probs[i,0]:.4f}") 

# %%

len(preprocessed)
print(preprocessed[:10])
print(states)
print(states.index('NN'))

# %% This will take a few minutes to run => processes ~ 30,000 words

best_probs, best_paths = viterbi_forward(A, B, preprocessed, best_probs, best_paths, vocab)

# %%

preprocessed[1]

# %%

print(states)

# %% Test this function --> check for the word 'economy'

for i in range(len(states)):
    print(f"best_probs[{i},1]: {best_probs[i,1]:.4f}") 

# %% Run and test your function

pred = viterbi_backward(best_probs, best_paths, preprocessed, states)
m=len(pred)
print('The prediction for pred[-7:m-1] is: \n', preprocessed[-7:m-1], "\n", pred[-7:m-1], "\n")
print('The prediction for pred[0:8] is: \n', pred[0:7], "\n", preprocessed[0:7])

# %%

print('The third word is:', preprocessed[3])
print('Your prediction is:', pred[3])
print('Your corresponding label y is: ', y[3])

# %%

print(f"Accuracy of the Viterbi algoriginalthm is {compute_accuracy(pred, y):.4f}")
