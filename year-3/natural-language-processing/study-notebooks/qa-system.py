import torch
from transformers import AutoTokenizer, AutoModelForQuestionAnswering

# Load tokenizer and QA model
tokenizer = AutoTokenizer.from_pretrained("distilbert-base-cased-distilled-squad")
model = AutoModelForQuestionAnswering.from_pretrained("distilbert-base-cased-distilled-squad")

# Set up input
context = "The Stanford Question Answering Dataset (SQuAD) is a reading comprehension dataset consisting of questions posed by crowdworkers on a set of Wikipedia articles, where the answer to every question is a segment of text, or span, from the corresponding reading passage. SQuAD2.0 combines 100,000 questions from SQuAD1.1 with over 50,000 unanswerable questions written adversarially by crowdworkers to look similar to answerable ones. The questions cover a broad range of topics and context, and require a diverse set of reasoning skills."

question = "What is SQuAD and how many questions does it have?"

# Tokenize inputs
inputs = tokenizer(question, context, return_tensors='pt')

# Get answer
answer_start_scores, answer_end_scores = model(**inputs).values()
answer_start = torch.argmax(answer_start_scores)
answer_end = torch.argmax(answer_end_scores) + 1
answer = tokenizer.convert_tokens_to_string(tokenizer.convert_ids_to_tokens(inputs["input_ids"][0][answer_start:answer_end]))

# Print answer
print(f'Question: {question}\nAnswer: {answer}')