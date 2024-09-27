''''''
def group_by_owners(files):
    owners={}
    for key, value in files.items():
        if value not in owners:
            owners[value] = [key]
        else:
            owners[value].append(key)
    return owners

if __name__ == "__main__":    
    files = {
        'Input.txt': 'Randy',
        'Code.py': 'Stan',
        'Output.txt': 'Randy'
    }   
    print(group_by_owners(files))
