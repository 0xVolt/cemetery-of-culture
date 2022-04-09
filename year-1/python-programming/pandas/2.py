import pandas as pd

df = pd.DataFrame (
    {
        "Name": [
            "test0",
            "test1",
            "test2"
        ],

        "Age": [20, 21, 22],

        "Course": ["maths", "physics", "history"]
    }
)

df [df > 3 and df < 8]