import nbformat
with open("lista04.ipynb", "r", encoding="utf-8") as f:
    nb = nbformat.read(f, as_version=4)
for c in nb.cells:
    if c.cell_type == "code":
        if "concrete.csv" in c.source:
            s = c.source
            s = s.replace("        if val_costs[-1] < best_val_loss:\n            best_val_loss = val_costs[-1]\n                best_hparams", "            if val_costs[-1] < best_val_loss:\n                best_val_loss = val_costs[-1]\n                best_hparams")
            c.source = s
        elif "vehicle.csv" in c.source:
            s = c.source
            s = s.replace("        if val_costs[-1] < best_val_loss:\n            best_val_loss = val_costs[-1]\n                best_hparams", "            if val_costs[-1] < best_val_loss:\n                best_val_loss = val_costs[-1]\n                best_hparams")
            c.source = s
with open("lista04.ipynb", "w", encoding="utf-8") as f:
    nbformat.write(nb, f)
