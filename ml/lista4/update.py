import nbformat
with open("lista04.ipynb", "r", encoding="utf-8") as f:
    nb = nbformat.read(f, as_version=4)
for c in nb.cells:
    if c.cell_type == "code":
        if "concrete.csv" in c.source:
            s = c.source
            s = s.replace("learning_rates = [0.01, 0.05, 0.1]", "hidden_layer_sizes = [4, 8, 16, 32, 64, 128]\nlearning_rates = [0.01, 0.05, 0.1]")
            s = s.replace("for lr in learning_rates:", "for hidden_size in hidden_layer_sizes:\n    for lr in learning_rates:")
            s = s.replace("    for momentum in momentums:", "        for momentum in momentums:")
            s = s.replace("model = MLP(layer_sizes=[8, 32, 1]", "    model = MLP(layer_sizes=[8, hidden_size, 1]")
            s = s.replace("train_costs, val_costs = model.train(X_train", "    train_costs, val_costs = model.train(X_train")
            s = s.replace("final_val_loss = val_costs[-1]", "    final_val_loss = val_costs[-1]")
            s = s.replace("print(f\"LR:", "    # print(f\"LR:")
            s = s.replace("if final_val_loss < best_val_loss:", "    if final_val_loss < best_val_loss:")
            s = s.replace("best_val_loss = final_val_loss", "    best_val_loss = final_val_loss")
            s = s.replace("best_hparams = (lr, momentum)", "    best_hparams = (hidden_size, lr, momentum)")
            s = s.replace("best_model = model", "    best_model = model")
            s = s.replace("best_curves = (train_costs, val_costs)", "    best_curves = (train_costs, val_costs)")
            s = s.replace("LR={best_hparams[0]}, Momentum={best_hparams[1]}", "Hidden={best_hparams[0]}, LR={best_hparams[1]}, Momentum={best_hparams[2]}")
            c.source = s
        elif "vehicle.csv" in c.source:
            s = c.source
            s = s.replace("learning_rates = [0.01, 0.05, 0.1]", "hidden_layer_sizes = [4, 8, 16, 32, 64, 128]\nlearning_rates = [0.01, 0.05, 0.1]")
            s = s.replace("for lr in learning_rates:", "for hidden_size in hidden_layer_sizes:\n    for lr in learning_rates:")
            s = s.replace("    for momentum in momentums:", "        for momentum in momentums:")
            s = s.replace("model = MLP(layer_sizes=[18, 64, num_classes]", "    model = MLP(layer_sizes=[18, hidden_size, num_classes]")
            s = s.replace("train_costs, val_costs = model.train(X_train", "    train_costs, val_costs = model.train(X_train")
            s = s.replace("final_val_loss = val_costs[-1]", "    final_val_loss = val_costs[-1]")
            s = s.replace("print(f\"LR:", "    # print(f\"LR:")
            s = s.replace("if final_val_loss < best_val_loss:", "    if final_val_loss < best_val_loss:")
            s = s.replace("best_val_loss = final_val_loss", "    best_val_loss = final_val_loss")
            s = s.replace("best_hparams_clf = (lr, momentum)", "    best_hparams_clf = (hidden_size, lr, momentum)")
            s = s.replace("best_model_clf = model", "    best_model_clf = model")
            s = s.replace("best_curves_clf = (train_costs, val_costs)", "    best_curves_clf = (train_costs, val_costs)")
            s = s.replace("LR={best_hparams_clf[0]}, Momentum={best_hparams_clf[1]}", "Hidden={best_hparams_clf[0]}, LR={best_hparams_clf[1]}, Momentum={best_hparams_clf[2]}")
            c.source = s
with open("lista04.ipynb", "w", encoding="utf-8") as f:
    nbformat.write(nb, f)
