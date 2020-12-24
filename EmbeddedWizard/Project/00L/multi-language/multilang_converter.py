#!/usr/local/bin/python3
# --------------------------------------------------------------------------
# Copyright 2020 by Garmin Ltd. or its subsidiaries.
# Convert multi-string table of csv format to Embedded Wizard file
# --------------------------------------------------------------------------

import os
import csv
from datetime import datetime

INTPUT_FILENAME = "Strings.csv"
OUTPUT_FILENAME = "Strings.ewu"
OUTPUT_FILE_HEAD = "$version 10.00\n\n// This file is generated automatically.\n// Generated: "

STRING_BLOCK_HEADER = "$output false\nconst string "
STRING_BLOCK_TAIL = "\n);\n\n"

try:
    with open(INTPUT_FILENAME, encoding='utf-8') as csvfile:
        csv_rows = csv.reader(csvfile)
        languages = csv_rows.__next__()

        # Get the list of language
        language_list = []
        language_num = 0
        for lang in languages[1:]:
            if (len(lang) > 0):
                language_list.append(lang)
                language_num = language_num + 1

        # Write output file header
        now = datetime.now()
        output_file = open(OUTPUT_FILENAME, 'w')
        output_file.write(OUTPUT_FILE_HEAD + now.strftime("%Y/%m/%d %H:%M:%S") + "\n\n")

        # Process each string
        string_num = 0
        for row in csv_rows:
            language_idx = 0
            string_id = row[0]
            string_block = STRING_BLOCK_HEADER + string_id + " =\n("

            for string in row[1:]:
                if (len(string) > 0):
                    string_num = string_num + 1
                    unicode_str = str(string.encode('unicode_escape'))
                    unicode_str = unicode_str.replace("\\\\u", "\\u")
                    unicode_str = unicode_str.replace("\\\\n", "\\n")
                    unicode_str = unicode_str.replace("\\\\x", "\\u00")
                    unicode_str = unicode_str[2:-1]
                    string_block = string_block + "\n  " + language_list[language_idx] + " = \"" + unicode_str + "\";"
                language_idx = language_idx + 1
            string_block += STRING_BLOCK_TAIL
            output_file.write(string_block)

        output_file.close()
        print ("Generated %s of %d strings in %d languages" % (OUTPUT_FILENAME, string_num, language_num))
except Exception as e:
    print (e)
