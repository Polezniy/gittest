using System.Collections;
using System.Collections.Generic;
using UnityEngine;

public class DestroyOnCol : MonoBehaviour
{

    public GameObject _explosion;
    public GameObject _explosionInst;

    void OnCollisionEnter(Collision colision)
    {

       // Debug.Log("Destroyed"); //debug purposes


       _explosionInst = Instantiate(_explosion, transform.position, transform.rotation); //create a particle explosion

        Destroy(gameObject); //destroy the missile

    }

}
