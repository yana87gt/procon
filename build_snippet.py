import subprocess
import re
import os
import json

def run(cmd): 
    print(cmd)
    subprocess.call(cmd, shell=True)

# snippets -> library
def sublime_to_library():
    sublime_snippets = os.listdir("./snippets")
    for sublime_snippet in sublime_snippets:
        with open(os.path.join('snippets', sublime_snippet), 'r') as file1:
            text = file1.read()
            match_obj = re.match(r'''<snippet>
\s*<content><!\[CDATA\[
((.|\n)*)
\]\]></content>
\s*<tabTrigger>(.*)</tabTrigger>
\s*<scope>(.*)</scope>
</snippet>''', text)
            if match_obj is None:
                print("Not match!", text)
                continue
            code, _, tab_trigger, source = match_obj.groups()
            file_base = re.match(r'(.+)\.sublime-snippet', sublime_snippet).groups()[0]
            with open(os.path.join('library', file_base + '.cpp'), 'w') as file2:
                file2.write(f"""///
/// for vscode snippet
/// prefix: {tab_trigger}
///

{code}""")

'''

'''

# library -> .vscode(snippet)
def library_to_snippet():
    libraries = os.listdir("./library")
    snippet_json = dict()
    for library in libraries:
        with open(os.path.join('library', library), 'r') as input_file:
            text = input_file.read()
        match_obj = re.match(r'''///
/// for vscode snippet
/// prefix:\s*(.+)
///

((.|\n)+)''', text)
        if match_obj is None:
            print("Not match!", text)
            continue
        prefix, code, _ = match_obj.groups()
        file_base, file_extension = re.match(r'(.+)\.(.+)', library).groups()
        snippet_json[file_base] = {
            "prefix": prefix,
            "scope": "python" if file_extension == 'py' else file_extension,
            "body": code.split('\n')
        }
    with open(os.path.join('.vscode/procon.code-snippets'), 'w') as output_file:
        output_file.write(json.dumps(snippet_json, indent=4, ensure_ascii=False))

if __name__ == "__main__":
    library_to_snippet()
