# Machine Learning Practical Viva

## Practical 1: Uber Fare Prediction

### Notebook workflow

The Uber fare prediction notebook follows a standard supervised regression
workflow:

1. Load and inspect the dataset.
2. Perform exploratory data analysis.
3. Separate the input features from the target, `fare_amount`.
4. Split the data into training and testing sets with `train_test_split`.
5. Train a `RandomForestRegressor` on the training data.
6. Generate predictions for the test data.
7. Evaluate the model with MAE, MSE, RMSE, and R².

The `df.corr()` calculation in the exploratory analysis is performed before
the train-test split. This is acceptable for quick EDA. For final feature
selection or preprocessing, correlations and fitted transformations should be
determined using the training data to avoid test-set leakage.

## Regression Evaluation Metrics

### 1. MAE — Mean Absolute Error

**Definition:** MAE is the average of the absolute differences between the
actual values (`y_i`) and predicted values (`ŷ_i`).

**Why it is used:** It gives a straightforward average error in the same units
as the target. For `fare_amount`, an MAE of `$2.10` means that predictions are
off by `$2.10` on average. Unlike squared-error metrics, MAE does not
disproportionately amplify large errors.

**How to read it:** Lower is better. A value of `0` represents a perfect fit.

**Formula:**

```text
MAE = (1 / n) × Σ |yᵢ − ŷᵢ|
```

### 2. MSE — Mean Squared Error

**Definition:** MSE is the average of the squared differences between actual
and predicted values.

**Why it is used:** Squaring penalizes large errors much more heavily than
small errors. For example, a `$10` error contributes `100`, while two `$5`
errors contribute `25 + 25 = 50`. MSE is also smooth and differentiable,
which makes it convenient for optimization and loss functions.

**How to read it:** Lower is better. Its units are squared, such as
`USD²`, so it is mainly useful for comparing models or calculating RMSE.

**Formula:**

```text
MSE = (1 / n) × Σ (yᵢ − ŷᵢ)²
```

### 3. RMSE — Root Mean Squared Error

**Definition:** RMSE is the square root of MSE.

**Why it is used:** It returns the error to the same units as the target while
retaining MSE's sensitivity to large errors.

**How to read it:** Lower is better. Compare RMSE with MAE on the same test
set:

- If RMSE is noticeably higher than MAE, the model is making some large
  errors, possibly on outlier trips, airport rides, or heavy-traffic trips.
- If RMSE is close to MAE, the errors are more uniform in size.

**Formula:**

```text
RMSE = √MSE = √[(1 / n) × Σ (yᵢ − ŷᵢ)²]
```

### 4. R² — Coefficient of Determination

**Definition:** R² is the proportion of variance in the actual target values
explained by the model compared with always predicting the mean target value.

**Why it is used:** It is scale-free, so it indicates how much better the
model performs than a mean-prediction baseline regardless of the target's
units.

**How to read it:**

- `1.0` means that all target variance is explained.
- A value close to `0` means that the model barely improves on predicting the
  mean.
- A negative value means that the model performs worse than the mean baseline.

R² is often between `0` and `1`, although it can be negative for a poor model.

**Formula:**

```text
R² = 1 − [Σ (yᵢ − ŷᵢ)² / Σ (yᵢ − ȳ)²]
```

## Why Report Both MSE and RMSE?

MSE and RMSE contain the same information because RMSE is the square root of
MSE, but they serve different purposes:

- **MSE** is convenient for mathematical optimization and loss functions
  because it avoids the square root.
- **RMSE** is easier to interpret because it is expressed in the same units as
  the target, such as dollars.

## MAE Compared with RMSE

MAE treats errors linearly: a `$20` error is four times a `$5` error. MSE and
RMSE penalize large errors more strongly because they square the error.

Reporting MAE and RMSE together shows both:

- the typical prediction error (`MAE`), and
- whether unusually large errors are significantly affecting the model
  (`RMSE`).

Therefore, the final evaluation cell should report all four metrics:

```python
from sklearn.metrics import mean_absolute_error, mean_squared_error, r2_score
import numpy as np

mae = mean_absolute_error(y_test, y_pred)
mse = mean_squared_error(y_test, y_pred)
rmse = np.sqrt(mse)
r2 = r2_score(y_test, y_pred)

print("MAE:", mae)
print("MSE:", mse)
print("RMSE:", rmse)
print("R²:", r2)
```

# Practical 2: Email Spam Classification

The notebook classifies an email as either **Not Spam** (`0`, the negative
class) or **Spam** (`1`, the positive class) using `KNeighborsClassifier` and
`SVC`. The word-count columns are the input features and `Prediction` is the
target label.

## Confusion Matrix

A confusion matrix compares the actual (ground-truth) label with the label
predicted by the model. It shows the types of correct predictions and errors,
not only the total number of correct predictions.

| Actual / Predicted | Positive (1) / Spam | Negative (0) / Not Spam |
|---|---:|---:|
| **Positive (1) / Spam** | True Positive (TP) | False Negative (FN) |
| **Negative (0) / Not Spam** | False Positive (FP) | True Negative (TN) |

- **True Positive (TP):** The email is spam and the model predicts spam.
- **True Negative (TN):** The email is not spam and the model predicts not
  spam.
- **False Positive (FP), Type I error:** The email is not spam, but the model
  incorrectly marks it as spam. This may send a legitimate email to the spam
  folder.
- **False Negative (FN), Type II error:** The email is spam, but the model
  incorrectly marks it as not spam. This allows spam into the inbox.

In `scikit-learn`, `confusion_matrix(y_true, y_pred)` uses actual labels as
rows and predicted labels as columns. For labels ordered as `0, 1`, the
matrix is:

```text
                Predicted 0       Predicted 1
Actual 0             TN               FP
Actual 1             FN               TP
```

### Default Python Structure

The standard `scikit-learn` program structure is:

```python
from sklearn.metrics import confusion_matrix

cm = confusion_matrix(y_test, y_pred, labels=[0, 1])
print(cm)
```

The printed two-dimensional array follows this default structure:

```text
[[TN, FP],
 [FN, TP]]
```

## Classification Metrics

All four metrics below are calculated from TP, TN, FP, and FN. Unless stated
otherwise, the positive class is Spam (`1`).

### 1. Accuracy

**Meaning:** Accuracy is the fraction of all emails that the model classified
correctly. It counts both correctly detected spam and correctly detected
legitimate email.

```text
Accuracy = (TP + TN) / (TP + TN + FP + FN)
```

The numerator counts all correct predictions, while the denominator counts
all predictions. The score ranges from `0` to `1` (or `0%` to `100%`).
**Higher is better**: `1.0` means every prediction is correct. However,
accuracy can be misleading for imbalanced data. For example, if 95% of emails
are legitimate, a model that always predicts Not Spam gets 95% accuracy but
detects none of the spam.

### 2. Precision

**Meaning:** Precision answers: **Of all emails predicted as Spam, how many
were actually Spam?** It measures how trustworthy a positive prediction is.

```text
Precision = TP / (TP + FP)
```

The denominator contains all emails predicted as Spam, and the numerator
contains the ones that were actually Spam. The score ranges from `0` to `1`.
**Higher is better**: high precision means few false positives. In spam
filtering, it means emails placed in the spam folder are usually genuinely
spam. If
`TP + FP = 0`, precision is undefined because the model made no positive
predictions; metric libraries handle this case using a configured
zero-division rule.

### 3. Recall (Sensitivity)

**Meaning:** Recall answers: **Of all emails that were actually Spam, how many
did the model successfully detect?** It measures how completely the model
finds the positive class.

```text
Recall = TP / (TP + FN)
```

The denominator contains all emails that were actually Spam, and the numerator
contains the Spam emails detected by the model. The score ranges from `0` to
`1`. **Higher is better**: high recall means few false negatives. In spam
filtering, it means that little spam slips into the inbox. If `TP + FN = 0`,
there are no actual
positive examples in the evaluated data, so recall is undefined.

Precision and recall often trade off. Making the classifier more aggressive
about calling emails spam may increase recall but also increase false
positives and reduce precision.

### 4. F1 Score

**Meaning:** F1 is the harmonic mean of precision and recall. It is high only
when both precision and recall are high, so it is useful when one combined
score is needed and false positives and false negatives both matter.

```text
F1 = 2 × (Precision × Recall) / (Precision + Recall)
```

Substituting the confusion-matrix terms gives the equivalent formula:

```text
F1 = 2TP / (2TP + FP + FN)
```

The harmonic mean penalizes an imbalance between precision and recall. For
example, precision `1.00` and recall `0.10` produce an F1 score of about
`0.18`, not the arithmetic average of `0.55`. The score ranges from `0` to
`1`; **higher is better**. A perfect F1 score is `1.0`, while `0` is the
worst score. Use F1 when both false positives and false negatives matter.

## What Is a Kernel in SVM?

A kernel is a function `K(xᵢ, xⱼ)` that measures the similarity between two
feature vectors as an inner product in a possibly higher-dimensional feature
space:

```text
K(xᵢ, xⱼ) = φ(xᵢ)ᵀφ(xⱼ)
```

Here, `φ` maps the original features to another space. The **kernel trick**
computes the inner product directly using `K`, without explicitly creating all
the higher-dimensional coordinates. This can make data that is not linearly
separable in the original space separable in the transformed space.

Common kernels are:

- **Linear:** `K(xᵢ, xⱼ) = xᵢᵀxⱼ`
- **Polynomial:** `K(xᵢ, xⱼ) = (γ xᵢᵀxⱼ + r)^d`
- **RBF/Gaussian:** `K(xᵢ, xⱼ) = exp(-γ ||xᵢ - xⱼ||²)`

For the notebook's high-dimensional word-count features, a linear kernel is
usually a practical choice when the model is created with
`SVC(kernel="linear")`.

## How SVM Works and Classifies

Support Vector Machine (SVM) is a discriminative, margin-based classifier. It
learns a decision boundary (a hyperplane) that separates the two classes
while maximizing the margin, which is the distance between the boundary and
the closest training points.

For labels `yᵢ ∈ {-1, +1}`, a hard-margin linear SVM solves:

```text
minimize    (1 / 2) ||w||²
subject to  yᵢ(wᵀxᵢ + b) ≥ 1  for every training point i
```

The corresponding margin width is `2 / ||w||`. A soft-margin SVM allows some
violations when classes overlap. Its regularization parameter `C` controls the
trade-off between a wide margin and training errors:

- Larger `C` penalizes misclassification more strongly and can produce a
  narrower margin.
- Smaller `C` allows more violations in exchange for a wider margin and
  stronger regularization.

The closest training points are the **support vectors**. They determine the
position of the decision boundary; points far from the boundary generally do
not affect it. In the kernel form, the decision function is:

```text
f(x) = Σ [αₛ yₛ K(xₛ, x)] + b
```

where `xₛ` are support vectors. During prediction:

1. The model calculates the signed decision score `f(x)`.
2. If `f(x) ≥ 0`, it predicts the positive class, Spam (`1`).
3. If `f(x) < 0`, it predicts the negative class, Not Spam (`0`).

The absolute value `|f(x)|` indicates the distance-related confidence of the
decision: a value near zero is close to the boundary, while a larger value is
farther from it. It is not automatically a calibrated probability.

## How K-Nearest Neighbors (KNN) Works and Classifies

`KNeighborsClassifier` is a lazy, instance-based, non-parametric classifier.
During `.fit()`, it mainly stores the training feature vectors and their
labels instead of learning one global equation or decision boundary.

For a new email feature vector `x`:

1. Calculate its distance from the stored training examples. With the
   default Euclidean distance:

   ```text
   d(x, xᵢ) = √[Σⱼ (xⱼ − xᵢⱼ)²]
   ```

2. Select the `k` training examples with the smallest distances.
3. Count their labels and predict the class with the majority vote. With
   `n_neighbors=5`, four Spam neighbors and one Not Spam neighbor produce the
   Spam prediction (`1`).

The default vote gives every neighbor equal weight. With
`weights="distance"`, closer neighbors have more influence. Other distance
choices include Manhattan distance:

```text
d(x, xᵢ) = Σⱼ |xⱼ − xᵢⱼ|
```

Small `k` values create flexible, noisy boundaries and may overfit. Larger
`k` values produce smoother boundaries but may ignore local patterns and
underfit. KNN has very little training cost but prediction is slower because
it compares a new email with stored training examples. In high-dimensional
word-count data, irrelevant features and different feature scales can also
make distance-based classification less reliable.

## SVM and KNN Comparison

| Aspect | SVM | KNN |
|---|---|---|
| Training | Learns an optimized boundary | Stores training examples |
| Prediction | Uses the learned boundary and support vectors | Uses the nearest stored examples |
| Main control | Kernel and regularization `C` | Number of neighbors `k` |
| Boundary | Margin-based global boundary | Local, data-dependent boundary |
| Cost | More work during training; usually faster prediction | Fast training; potentially slower prediction |
| Strength | Effective in high-dimensional feature spaces | Simple and useful when local neighborhoods are meaningful |

The models should be compared on the same held-out test set using accuracy,
precision, recall, F1 score, and the confusion matrix. For spam detection,
precision is important when legitimate email must not be blocked, while recall
is important when missing spam is the bigger concern.

# Practical 3: Bank Customer Churn Prediction with an ANN

## Neural Network Viva Questions and Answers

### 1. What is a Neural Network?

A Neural Network (NN) is a machine learning model made of connected
mathematical units called neurons. It learns patterns by adjusting weights and
biases while processing input data through layers.

In this practical, customer features such as credit score, age, balance, and
geography are used to predict whether a customer will exit (`Exited = 1`) or
stay (`Exited = 0`).

### 2. What is an ANN?

ANN stands for **Artificial Neural Network**. It is a computing model inspired
by the way biological neurons process information. An ANN accepts input
features, transforms them through hidden layers, and produces an output such
as a class or probability.

### 3. How does a neural network work?

Training follows these steps:

1. **Forward pass:** Inputs pass through the layers to produce a prediction.
2. **Loss calculation:** The prediction is compared with the true answer.
3. **Backpropagation:** Gradients are calculated to show how each parameter
   contributed to the error.
4. **Weight update:** The optimizer adjusts the weights and biases.

This process repeats for many batches and epochs.

### 4. What are weights and biases?

**Weights** determine the importance of input values. **Biases** shift the
activation value and help a neuron fit the data. Both are learnable parameters
updated during training.

### 5. What is a neuron or unit?

A neuron calculates a weighted sum of its inputs, adds a bias, and applies an
activation function:

```text
output = activation(weighted_sum + bias)
```

### 6. What is a layer?

A layer is a group of neurons that performs a transformation on its input.
Common types include input layers, dense layers, convolutional layers,
recurrent layers, dropout layers, and batch-normalization layers.

### 7. What is `Sequential`?

`Sequential` is a Keras model structure in which layers are arranged in a
linear stack. The output of one layer becomes the input to the next layer.
It is suitable when the model has a simple one-directional flow.

### 8. What is a `Dense` layer?

A `Dense` layer is a fully connected layer. Every neuron receives input from
every neuron in the previous layer. For example, a model can use:

```text
Dense(16) -> Dense(8) -> Dense(1)
```

The final `Dense(1)` unit is suitable for binary classification when it uses a
sigmoid activation.

### 9. What is an activation function?

An activation function transforms a neuron's value and introduces
non-linearity. Without non-linearity, multiple dense layers would behave like
one linear equation and could not learn complex patterns.

### 10. What is ReLU?

ReLU means **Rectified Linear Unit**. It is defined as:

```text
ReLU(x) = max(0, x)
```

It outputs zero for negative values and keeps positive values unchanged. ReLU
is commonly used in hidden layers because it is simple and usually helps
training remain efficient.

### 11. What is sigmoid?

Sigmoid converts any real number into a value between `0` and `1`:

```text
sigmoid(x) = 1 / (1 + e^(-x))
```

It is commonly used in the output layer for binary classification. The output
can be interpreted as the probability of the positive class, such as a
customer leaving the bank.

### 12. What is Batch Normalization?

`BatchNormalization` normalizes intermediate values in a mini-batch by
centering and scaling them. It can make training more stable and reduce
sensitivity to parameter initialization. It also maintains moving mean and
variance values for use during evaluation and prediction.

### 13. What is Dropout?

Dropout is a regularization technique that randomly sets a fraction of neuron
outputs to zero during training. For example, `Dropout(0.2)` temporarily drops
about 20% of the outputs in each training step.

It prevents neurons from becoming too dependent on one another and helps
reduce overfitting. Dropout is active during training but is automatically
disabled during evaluation and prediction.

### 14. What are some other common layers?

- **Input:** Defines the shape of the input features.
- **Conv2D:** Learns spatial patterns in images.
- **MaxPooling2D:** Reduces the spatial size of image features.
- **LSTM/GRU:** Processes sequential or time-series data.
- **Flatten:** Converts multi-dimensional data into a one-dimensional vector.

### 15. What is `compile()`?

`model.compile()` configures the model before training. It specifies the
optimizer, loss function, and evaluation metrics. It does not train the model.
Training starts when `model.fit()` is called.

### 16. What is an optimizer?

An optimizer uses gradients from backpropagation to update weights and biases
so that the loss decreases. The learning rate controls the size of each update.

### 17. What is Adam?

Adam means **Adaptive Moment Estimation**. It combines momentum, which smooths
the direction of updates, with adaptive learning rates for individual
parameters. It is a popular optimizer because it generally works well without
extensive initial tuning.

### 18. What is a loss function?

A loss function measures how different the model's prediction is from the true
answer. The optimizer tries to minimize this value. A lower loss generally
means the model's predictions are closer to the targets.

### 19. What is binary cross-entropy?

Binary cross-entropy is a loss function for two-class classification. It is
defined as:

```text
Loss = -[y log(p) + (1 - y) log(1 - p)]
```

Here, `y` is the actual label and `p` is the predicted probability. It
penalizes confident wrong predictions heavily, so it is appropriate when the
output layer uses sigmoid.

### 20. What is a batch?

A batch is a subset of training examples processed before the model updates
its weights. Processing data in batches uses less memory and provides frequent
weight updates.

### 21. What is `batch_size`?

`batch_size` specifies the number of samples in one batch. For example,
`batch_size=32` means the model processes 32 samples and then performs one
weight update. If the training set has 6,400 samples, it contains 200 batches
of 32 samples.

### 22. What is an epoch?

An epoch is one complete pass through all training samples. If `epochs=25`,
the model can see the training data up to 25 times, unless a callback such as
early stopping ends training sooner.

### 23. What is `validation_split`?

`validation_split=0.2` reserves 20% of the supplied training data for
validation. The model does not update its weights using these validation
samples; it uses them to measure performance after each epoch. The separate
test set should remain untouched until final evaluation.

### 24. What is `verbose`?

`verbose` controls the amount of training output:

- `verbose=0`: No output.
- `verbose=1`: Shows a progress bar and metrics.
- `verbose=2`: Shows one summary line for each epoch.

### 25. What is overfitting?

Overfitting occurs when a model memorizes training examples and performs well
on training data but poorly on unseen data. Dropout, batch normalization,
regularization, early stopping, and more data can help reduce it.

### 26. What is underfitting?

Underfitting occurs when a model is too simple or insufficiently trained to
learn the important patterns in the data. Increasing suitable model capacity
or training time may help, provided overfitting is monitored.

### 27. What is the difference between training, validation, and test data?

- **Training data:** Used to learn weights and biases.
- **Validation data:** Used during development to monitor and tune the model.
- **Test data:** Used at the end to estimate performance on unseen data.

### 28. Why are ReLU and sigmoid used in different layers?

ReLU is generally used in hidden layers because it efficiently learns
non-linear representations. Sigmoid is used in the final binary-classification
layer because it converts the result into a probability from `0` to `1`.

# Practical 6: Sales Data Clustering

## Clustering Viva Questions and Answers

### 1. What was done in this practical?

This practical used **unsupervised learning** to group 2,823 sales orders from
`sales_data_sample.csv`. Since there were no pre-existing class labels, the
goal was to discover natural groups based on:

- `QUANTITYORDERED`: number of items in the order.
- `SALES`: total sales value of the order.

The CSV was read with `encoding='latin1'` to support special characters.
Both features were standardized with `StandardScaler`, the elbow method was
used to select `k=3`, and the results from K-Means and Agglomerative
Clustering were compared using internal validation scores.

### 2. What is unsupervised learning?

Unsupervised learning finds patterns or groups in data without a target label.
Clustering is an unsupervised task because the algorithm decides which
observations belong together.

### 3. Why was feature scaling performed?

`SALES` has much larger numerical values than `QUANTITYORDERED`. Because
clustering uses distances, the unscaled sales feature would dominate the
distance calculation. `StandardScaler` transforms each feature as:

```text
z = (x - mean) / standard_deviation
```

After scaling, each feature has approximately mean `0` and standard deviation
`1`, so both features have a comparable effect.

### 4. What is K-Means clustering?

K-Means is a partition-based clustering algorithm that divides observations
into `K` non-overlapping clusters. Each cluster is represented by a centroid,
which is the mean position of its assigned points.

Its steps are:

1. Choose `K` initial centroids.
2. Assign each point to its nearest centroid.
3. Recalculate each centroid as the mean of its assigned points.
4. Repeat assignment and recalculation until the centroids stabilize or the
   iteration limit is reached.

The distance commonly used is Euclidean distance:

```text
d(x, y) = sqrt(sum((x_j - y_j)^2))
```

### 5. What is hierarchical clustering?

Hierarchical clustering builds a hierarchy of nested groups. The result can be
shown using a dendrogram, which displays the order and distance at which
clusters were joined or divided.

There are two approaches:

- **Agglomerative:** Bottom-up; starts with every point as its own cluster and
  repeatedly merges the closest clusters.
- **Divisive:** Top-down; starts with one large cluster and repeatedly splits
  it.

### 6. What is Agglomerative Clustering?

Agglomerative Clustering is the bottom-up hierarchical method used in this
practical. It began with each of the 2,823 orders as a separate cluster and
merged clusters until `n_clusters=3` remained.

With the default **Ward linkage**, each merge is selected to cause the
smallest increase in within-cluster variance. Unlike K-Means, it does not
recalculate centroids through repeated random assignments.

### 7. What groups were found?

With three clusters, the orders can be interpreted approximately as:

- Low quantity and low sales.
- Medium quantity and medium sales.
- High quantity and high sales.

Cluster labels such as `0`, `1`, and `2` are only identifiers. They do not
automatically mean low, medium, or high until the cluster statistics are
examined.

### 8. What is WCSS?

WCSS means **Within-Cluster Sum of Squares**. In scikit-learn, it is reported
as K-Means `inertia_`. It measures how far points are from the centroid of
their assigned cluster:

```text
WCSS = sum(i=1 to K) sum(x in C_i) ||x - mu_i||^2
```

Here, `C_i` is cluster `i` and `mu_i` is its centroid. A lower WCSS means
clusters are more compact. WCSS is always non-increasing as `K` increases,
so it must not be used alone to choose a very large number of clusters.

### 9. What is the elbow method?

The elbow method runs K-Means for several values of `K`, plots `K` against
WCSS, and looks for the point where the rapid decrease begins to level off.
That bend is the **elbow**: adding more clusters after it gives only a
relatively small improvement.

In this practical, the curve bent around `K=3`, so three clusters were used.
The elbow is a judgment rather than an absolute proof; it should be checked
with cluster interpretation and validation metrics.

### 10. What is the Silhouette Score?

For a point `i`, the silhouette value is:

```text
s(i) = (b(i) - a(i)) / max(a(i), b(i))
```

- `a(i)`: average distance from `i` to points in its own cluster.
- `b(i)`: average distance from `i` to points in the nearest other cluster.

The reported score is the average of `s(i)` for all points. It ranges from
`-1` to `+1`:

- Near `+1`: compact and well-separated clusters; **higher is better**.
- Near `0`: overlapping clusters or points near boundaries.
- Below `0`: points may be assigned to the wrong cluster.

The notebook results were approximately K-Means `0.412` and Hierarchical
Clustering `0.383`. Therefore, K-Means had slightly better overall
cohesion and separation according to this metric.

### 11. What is the Calinski-Harabasz Score?

The Calinski-Harabasz (CH) score compares between-cluster dispersion with
within-cluster dispersion:

```text
CH = [SSB / (K - 1)] / [SSW / (N - K)]
```

- `SSB`: between-cluster sum of squares, measuring how far cluster centers
  are from the overall data center.
- `SSW`: within-cluster sum of squares, measuring spread inside clusters.
- `N`: number of samples.
- `K`: number of clusters.

There is no fixed maximum. **Higher is better** when comparing models on the
same dataset and feature representation because it indicates separated
clusters with less internal spread. The notebook results were approximately
K-Means `2924.15` and Hierarchical `2306.82`, favoring K-Means.

### 12. What is the Davies-Bouldin Index?

The Davies-Bouldin Index (DBI) measures the average similarity between every
cluster and its most similar neighboring cluster:

```text
DBI = (1 / K) * sum(i=1 to K) max(j != i) [(S_i + S_j) / M_ij]
```

- `S_i` and `S_j`: average spread of clusters `i` and `j` around their
  centroids.
- `M_ij`: distance between the centroids of clusters `i` and `j`.

The index has a lower-is-better interpretation. A value near `0` is ideal:
clusters are compact and far apart. A high value means at least some clusters
are spread out or close to one another. The notebook results were
approximately K-Means `0.872` and Hierarchical `0.814`, so Hierarchical
Clustering performed slightly better according to DBI.

### 13. How should the clustering scores be evaluated together?

No single score proves that one clustering is best. A useful interpretation is:

| Metric | Desired direction | What it evaluates |
|---|---|---|
| WCSS / inertia | Lower, while avoiding too many clusters | Compactness around centroids |
| Silhouette | Higher, up to `1` | Cohesion and separation |
| Calinski-Harabasz | Higher | Between-cluster separation versus within-cluster spread |
| Davies-Bouldin | Lower, with `0` ideal | Similarity and overlap between clusters |

For this practical, K-Means was better on Silhouette and Calinski-Harabasz,
while Agglomerative Clustering was slightly better on Davies-Bouldin. The
final choice should also consider whether the resulting clusters are
understandable and useful for sales decisions.
