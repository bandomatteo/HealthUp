#ifndef MODEL_H
#define MODEL_H

class Model
{
public:
    /**
     * @brief Distruttore virtuale c

     */
     virtual ~Model() = default;
protected:
    /**
     * @brief Costruttore di Model. Sarò un oggetto costruibile solamente dalle classe derivate
     */
    explicit Model();
};

#endif // MODEL_H
