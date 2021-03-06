/**
 @file
 @author  Nicholas Gillian <ngillian@media.mit.edu>
 @version 1.0
 
 @brief This file implements a DecisionTreeTripleFeatureNode, which is a specific type of node used for a DecisionTree.
 */

/**
 GRT MIT License
 Copyright (c) <2012> <Nicholas Gillian, Media Lab, MIT>
 
 Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 and associated documentation files (the "Software"), to deal in the Software without restriction,
 including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
 and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so,
 subject to the following conditions:
 
 The above copyright notice and this permission notice shall be included in all copies or substantial
 portions of the Software.
 
 THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT
 LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
 IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
 WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
 SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
 */

#ifndef GRT_DECISION_TREE_TRIPLE_FEATURE_NODE_HEADER
#define GRT_DECISION_TREE_TRIPLE_FEATURE_NODE_HEADER

#include "DecisionTreeNode.h"
#include "../../ClusteringModules/KMeans/KMeans.h"

GRT_BEGIN_NAMESPACE
    
class GRT_API DecisionTreeTripleFeatureNode : public DecisionTreeNode{
public:
    /**
     Default Constructor. Sets all the pointers to NULL.
     */
    DecisionTreeTripleFeatureNode();
    
    /**
     Default Destructor. Cleans up any memory.
     */
    virtual ~DecisionTreeTripleFeatureNode();
    
    /**
     This function predicts if the input is greater than or equal to the nodes threshold.
     If the input is greater than or equal to the nodes threshold then this function will return true, otherwise it will return false.
     
     NOTE: The threshold and featureIndex should be set first BEFORE this function is called.
     
     @param x: the input Vector that will be used for the prediction
     @return returns true if the input is greater than or equal to the nodes threshold, false otherwise
     */
    virtual bool predict(const VectorFloat &x);
    
    /**
     This functions cleans up any dynamic memory assigned by the node.
     It will recursively clear the memory for the left and right child nodes.
     
     @return returns true of the node was cleared correctly, false otherwise
     */
    virtual bool clear();
    
    /**
     This functions prints the node data to std::out.
     It will recursively print all the child nodes.
     
     @return returns true if the data was printed correctly, false otherwise
     */
    virtual bool print() const;
    
    /**
     This function adds the current model to the formatted stream.
     This function should be overwritten by the derived class.
     
     @param file: a reference to the stream the model will be added to
     @return returns true if the model was added successfully, false otherwise
     */
    virtual bool getModel( std::ostream &stream ) const;
    
    /**
     This function returns a deep copy of the DecisionTreeTripleFeatureNode and all it's children.
     The user is responsible for managing the dynamic data that is returned from this function as a pointer.
     
     @return returns a pointer to a deep copy of the DecisionTreeTripleFeatureNode, or NULL if the deep copy was not successful
     */
    virtual Node* deepCopyNode() const;
    
    /**
     This function returns a deep copy of the DecisionTreeTripleFeatureNode and all it's children.
     The user is responsible for managing the dynamic data that is returned from this function as a pointer.
     
     @return returns a pointer to a deep copy of the DecisionTreeTripleFeatureNode, or NULL if the deep copy was not successful
     */
    DecisionTreeTripleFeatureNode* deepCopy() const;
    
    /**
     This function returns the first featureIndex.
     
     @return returns the first featureIndex
     */
    UINT getFeatureIndexA() const;
     
    /**
     This function returns the second featureIndex.
     
     @return returns the second featureIndex
     */
    UINT getFeatureIndexB() const;
    
    /**
     This function returns the third featureIndex.
     
     @return returns the third featureIndex
     */
    UINT getFeatureIndexC() const;
    
    /**
     This function sets the Decision Tree Threshold Node.
     
     @param nodeSize: sets the node size, this is the number of training samples at that node
     @param featureIndexA: sets the first index of the feature that should be used for the threshold spilt
     @param featureIndexB: sets the second index of the feature that should be used for the threshold spilt
     @param featureIndexC: sets the third index of the feature that should be used for the threshold spilt
     @param classProbabilities: the Vector of class probabilities at this node
     @return returns true if the node was set, false otherwise
     */
    bool set(const UINT nodeSize,const UINT featureIndexA,const UINT featureIndexB,const UINT featureIndexC,const VectorFloat &classProbabilities);
    
protected:
    
    virtual bool computeBestSpiltBestIterativeSpilt( const UINT &numSplittingSteps, const ClassificationData &trainingData, const Vector< UINT > &features, const Vector< UINT > &classLabels, UINT &featureIndex, Float &minError );
    
    virtual bool computeBestSpiltBestRandomSpilt( const UINT &numSplittingSteps, const ClassificationData &trainingData, const Vector< UINT > &features, const Vector< UINT > &classLabels, UINT &featureIndex, Float &minError );
    
    bool computeBestSpilt( const UINT &numSplittingSteps, const ClassificationData &trainingData, const Vector< UINT > &features, const Vector< UINT > &classLabels, UINT &featureIndex, Float &minError );
    
    /**
     This saves the DecisionTreeNode custom parameters to a file. It will be called automatically by the Node base class
     if the saveToFile function is called.
     
     @param file: a reference to the file the parameters will be saved to
     @return returns true if the model was saved successfully, false otherwise
     */
    virtual bool saveParametersToFile( std::fstream &file ) const;
    
    /**
     This loads the Decision Tree Node parameters from a file.
     
     @param file: a reference to the file the parameters will be loaded from
     @return returns true if the model was loaded successfully, false otherwise
     */
    virtual bool loadParametersFromFile( std::fstream &file );
    
    UINT featureIndexA;
    UINT featureIndexB;
    UINT featureIndexC;
    static RegisterNode< DecisionTreeTripleFeatureNode > registerModule;
};

GRT_END_NAMESPACE

#endif //GRT_DECISION_TREE_TRIPLE_FEATURE_NODE_HEADER

