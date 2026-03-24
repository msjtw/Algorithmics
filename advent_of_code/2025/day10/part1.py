from pulp import *
import sys
import re


def parse_line(line):
    bracket_match = re.search(r'\[(.*?)\]', line)
    bracket_content = bracket_match.group(1)

    bracket_array = [1 if c == '#' else 0 for c in bracket_content]
    length = len(bracket_array)

    paren_contents = re.findall(r'\((.*?)\)', line)
    paren_arrays = []

    for content in paren_contents:
        content = content.strip()
        if not content:
            continue

        arr = [0] * length
        indices = [int(x) for x in content.split(',')]
        for i in indices:
            arr[i] = 1
        paren_arrays.append(arr)

    return bracket_array, paren_arrays


def main():
    res = 0
    for line in sys.stdin:
        line = line.strip()

        results, constraints = parse_line(line)
        constraints = [list(row) for row in zip(*constraints)]

        # for i in range(len(constraints)):
        #     print(constraints[i], results[i])
        # print()

        prob = LpProblem("aoc_day10", LpMinimize)

        # variables
        lst_switch = ["switch_"+str(i) for i in range(len(constraints[0]))]
        lst_parity = ["parity_"+str(i) for i in range(len(results))]
        lst = lst_switch + lst_parity

        switch_vars = LpVariable.dicts("", lst_switch, 0, cat='Integer')
        parity_vars = LpVariable.dicts("", lst_parity, cat='Integer')
        vars = {**switch_vars, **parity_vars}

        # goal function
        prob += (
            lpSum([switch_vars[i] for i in lst_switch]),
            "Total swich count",
        )

        # constraints
        for i in range(len(results)):
            switch_cons = constraints[i]
            parity_cons = len(parity_vars)*[0]
            parity_cons[i] = 2
            cons_list = switch_cons + parity_cons
            cons = dict.fromkeys(lst)
            for k in range(len(lst)):
                cons[lst[k]] = cons_list[k]

            prob += (
                lpSum([cons[k] * vars[k]
                      for k in lst]) == results[i], "ligt_state_"+str(i),
            )

        # solev
        status = prob.solve(PULP_CBC_CMD(msg=False))
        # print(pulp.value(prob.objective))
        res += pulp.value(prob.objective)

    print(res)


if __name__ == "__main__":
    main()
