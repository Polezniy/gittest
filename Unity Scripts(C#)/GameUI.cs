using System.Collections;
using System.Collections.Generic;
using UnityEngine;
using UnityEngine.UI;

public class GameUI : MonoBehaviour
{

    public Scrollbar _thrust;
    public Button _fireButton;
    public Rigidbody _missileprefab;
    public GameObject _heli;
    public Transform _spawnPos;

    private Rigidbody _missileInst;
    private bool _spawned; //flag

    public float deltaTime = 0.0f;
    public float fps = 0.0f;
    public Text _fpcCounter;
    void Start ()
    {
        _spawned = false;
        Button _btn2 = _fireButton.GetComponent<Button>();
        _btn2.onClick.AddListener(_firing);
    }

    void Update()
    {
        deltaTime += Time.deltaTime;
        deltaTime /= 2.0f;
        fps = 1.0f / deltaTime;

        _fpcCounter.text = "" + fps;

        Debug.Log(fps);
    }
    // Update is called once per frame
    void FixedUpdate()
    {

        Scrollbar _scrl = _thrust.GetComponent<Scrollbar>();

        _heli.GetComponent<Transform>().Translate(0, _scrl.value * Time.deltaTime, 0); //up

        if (_scrl.value == 0 && _heli.transform.position.y != -0.01) //down
        {
            _heli.GetComponent<Transform>().Translate(0, _scrl.value-0.5f * Time.deltaTime, 0);
        }

        if (_spawned == true && _missileInst != null)
        {
            _missileInst.AddForce(0, -8 * Time.deltaTime, 5 * Time.deltaTime);
        }

        if(_missileInst != null) // FLAGS FOR PROPPER SPAWNING
        {
            _spawned = true;
        }
        else
        {
            _spawned = false;
        }
    }

    void _firing() //function that instantiates a missile at spawning point
    {
        if (_spawned == false)
        {
            _missileInst = Instantiate(_missileprefab, _spawnPos.position, _spawnPos.rotation) as Rigidbody;
        }
    }


}
